extern u8 sDeferGravSwap;
extern u8 gDisableGravity;

void bhv_ccm_flipper_loop()
{
    gDisableGravity = 0;
    f32 hbSize = 150.f;
    if (o->oDistanceToMario < hbSize)
    {
        sDeferGravSwap = 1;
        o->activeFlags = 0;
    }

    if ((o->oTimer % 8) == 0)
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX = o->oPosX + random_f32_around_zero(50.f);
        spark->oPosY = o->oPosY  + random_f32_around_zero(50.f);
        spark->oPosZ = o->oPosZ + random_f32_around_zero(50.f);
    }
}

void bhv_ccm_flipper_up_reset()
{
    gDisableGravity = 0;
}

void bhv_ccm_flipper_up()
{
    f32 dx = gMarioStates->pos[0] - o->oPosX;
    f32 dz = gMarioStates->pos[2] - o->oPosZ;
    f32 dist = dx*dx + dz*dz;
    if (dist > 15000.f)
        return;
    
    if (o->oPosY < gMarioStates->pos[1] && gMarioStates->pos[1] < o->oPosY + 1500.f)
    {
        gDisableGravity = 1;
        gMarioStates->action = ACT_JUMP;

        f32 raisevel = 4.f;
        gMarioStates->vel[1] += raisevel;

        f32 maxvel = 60.f;
        if (gMarioStates->vel[1] > maxvel)
            gMarioStates->vel[1] = maxvel;
    }
}
