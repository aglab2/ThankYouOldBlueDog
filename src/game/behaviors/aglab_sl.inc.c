void bhv_sl_ctl_init()
{
    o->oFaceAnglePitch = 0xA000;
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
        }
    }
    else
    {
        s16 marioAngleToZero = atan2s(gMarioStates->pos[1] + 40.f, gMarioStates->pos[2]);
        o->oFaceAnglePitch += 0x80;
        s16 angleDiff = o->oFaceAnglePitch - 0x2000 - marioAngleToZero;
        if (ABS(angleDiff) > 11800)
        {
            gMarioStates->action = 0;
        }
    }
}
