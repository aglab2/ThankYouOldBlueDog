#define oSlCtlTurnsAmount oF4
#define oSlCtlTurnsDirection oF8
#define oSlCtlCount oFC

#define SL_SPEED (0x78 + 8 * o->oSlCtlCount)

void bhv_sl_ctl_init()
{
    o->oFaceAnglePitch = 0xA000;
    o->oSlCtlCount = 0;
}

void bhv_sl_ctl_loop()
{
    gCamera->cutscene = CUTSCENE_SL_SPIN;
    gMarioStates->pos[0] = 0.f;

    if (0 == o->oAction)
    {
        if (gMarioStates->floor->type != SURFACE_NOT_SLIPPERY)
        {
            o->oAction = 1;
            o->oSlCtlTurnsDirection = gMarioStates->pos[2] > 0 ? -1 : 1;
            o->oSlCtlTurnsAmount = (0x4000 / SL_SPEED) * ((random_u16() & 1) + 2);
        }
    }
    else
    {
        if (o->oAction != 3)
        {
            if (0 == o->oSlCtlTurnsAmount)
            {
                o->oSlCtlCount++;
                o->oSlCtlTurnsAmount = (0x4000 / SL_SPEED) * (int) ((1 + random_float() * 3));
                o->oSlCtlTurnsDirection = random_u16() & 1 ? -1 : 1;
                o->oAction = 2;
            }
            else
            {
                if (1 == o->oAction)
                {
                    o->oSlCtlTurnsAmount--;
                    o->oFaceAnglePitch += o->oSlCtlTurnsDirection * SL_SPEED;
                }
                else
                {
                    if (o->oTimer > 60)
                    {
                        o->oAction = 1;
                    }
                }
            }

            if (gMarioStates->action && 5 == o->oSlCtlCount)
            {
                spawn_default_star(0, -998, 0);
                o->oAction = 3;
                cur_obj_hide();
            }

            s16 marioAngleToZero = atan2s(gMarioStates->pos[1] + 40.f, gMarioStates->pos[2]);
            s16 angleDiff = o->oFaceAnglePitch - 0x2000 - marioAngleToZero;
            if (ABS(angleDiff) > 11800)
            {
                gMarioStates->action = 0;
            }
        }
    }
}
