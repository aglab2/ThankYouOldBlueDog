static const u8 kSslFloors[] = { SURFACE_HARD, SURFACE_HARD_NOT_SLIPPERY, SURFACE_NOISE_DEFAULT, -1 };

void bhv_ssl_loop()
{
    if (!gMarioStates->floor)
        return;

    if (kSslFloors[o->oAction] == gMarioStates->floor->type)
    {
        for (int i = 0; i < 50; i++)
        {
            struct Object* obj = spawn_object(o, MODEL_GOOMBA, bhvGoomba);
            obj->oPosX = -500.f - random_float() * 3000.f;
            obj->oPosY = -120.f;
            obj->oPosZ = 500.f + random_float() * 3000.f;
        }

        o->oAction++;
    }
}
