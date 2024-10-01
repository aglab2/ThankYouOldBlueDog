#define oSlCtlTurnsAmount oF4
#define oSlCtlTurnsDirection oF8
#define oSlCtlCount oFC
#define oSlCtlTurnsAmountBg o100

#define SL_SPEED ((gIsHM ? 0xA0 : 0x7C) + (gIsHM ? 0x10 : 0x5) * o->oSlCtlCount)

static uint8_t kSlCyclesAmounts[] = { 1, 2, 2, 3, 3 };
static int8_t kSlTurnDirections[] = { 1, 1, 1, -1, -1, -1 };

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
            shuffle_u8(kSlCyclesAmounts, sizeof(kSlCyclesAmounts));
            shuffle_u8(kSlTurnDirections, sizeof(kSlTurnDirections));
        }
    }
    else
    {
        if (o->oAction != 3)
        {
            if (0 == o->oSlCtlTurnsAmount)
            {
                int cyclesAmount = (4 * gIsHM) + (o->oSlCtlCount < sizeof(kSlCyclesAmounts) ? kSlCyclesAmounts[o->oSlCtlCount] : (1 + (random_u16() & 3)));
                o->oSlCtlTurnsDirection = (o->oSlCtlCount < sizeof(kSlTurnDirections) ? kSlTurnDirections[o->oSlCtlCount] : (random_u16() & 1) ? -1 : 1);
                o->oSlCtlCount++;
                o->oSlCtlTurnsAmount = (0x4000 / SL_SPEED) * cyclesAmount;
                o->oSlCtlTurnsAmountBg = (0x4000 / SL_SPEED / 2) + (0x4000 / SL_SPEED) * (cyclesAmount - 1);
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
                    else
                    {
                        o->parentObj->oFaceAnglePitch = ((((u16)(o->parentObj->oFaceAnglePitch) + 0x400) & 0xF800));
                    }
                }
                else
                {
                    o->oFaceAnglePitch = 0x2000 + ((o->oFaceAnglePitch) & 0xC000);
                    if (o->oTimer > (gIsHM ? (20 + 3*o->oSlCtlCount) : 45))
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
