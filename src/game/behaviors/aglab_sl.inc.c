#define oSlCtlTurnsAmount oF4
#define oSlCtlTurnsDirection oF8
#define oSlCtlCount oFC
#define oSlCtlTurnsAmountBg o100

#define SL_SPEED (0x78 + 8 * o->oSlCtlCount)

static uint8_t kSlCyclesAmounts[] = { 1, 2, 2, 3, 4 };

void bhv_sl_ctl_init()
{
    o->oFaceAnglePitch = 0xA000;
    o->oSlCtlCount = 0;

    o->parentObj = spawn_object(o, MODEL_SL_STAR, bhvStaticObject);
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
            int cyclesAmount = ((random_u16() & 1) + 2);
            o->oSlCtlTurnsAmount = (0x4000 / SL_SPEED) * cyclesAmount;
            o->oSlCtlTurnsAmountBg = (0x4000 / SL_SPEED / 2) + (0x4000 / SL_SPEED) * (cyclesAmount - 1);
            for (int i = 0; i < sizeof(kSlCyclesAmounts); i++)
            {
                int idx = random_u16() % sizeof(kSlCyclesAmounts);
                uint8_t tmp = kSlCyclesAmounts[i];
                kSlCyclesAmounts[i] = kSlCyclesAmounts[idx];
                kSlCyclesAmounts[idx] = tmp;
            }
        }
    }
    else
    {
        if (o->oAction != 3)
        {
            if (0 == o->oSlCtlTurnsAmount)
            {
                int cyclesAmount = kSlCyclesAmounts[o->oSlCtlCount];
                o->oSlCtlCount++;
                o->oSlCtlTurnsAmount = (0x4000 / SL_SPEED) * cyclesAmount;
                o->oSlCtlTurnsAmountBg = (0x4000 / SL_SPEED / 2) + (0x4000 / SL_SPEED) * (cyclesAmount - 1);
                o->oSlCtlTurnsDirection = random_u16() & 1 ? -1 : 1;
                o->oAction = 2;
            }
            else
            {
                if (1 == o->oAction)
                {
                    o->oSlCtlTurnsAmount--;
                    o->oFaceAnglePitch += o->oSlCtlTurnsDirection * SL_SPEED;
                    if (o->oSlCtlTurnsAmountBg)
                    {
                        o->oSlCtlTurnsAmountBg--;
                        o->parentObj->oFaceAnglePitch -= (o->oSlCtlTurnsDirection * SL_SPEED / 4.f);
                    }
                }
                else
                {
                    if (o->oTimer > 60)
                    {
                        o->oAction = 1;
                    }
                }
            }

            if (gMarioStates->action && 6 == o->oSlCtlCount)
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
