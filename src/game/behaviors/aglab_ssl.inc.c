static const u8 kSslFloors[] = { SURFACE_HARD, SURFACE_HARD_NOT_SLIPPERY, SURFACE_NOISE_DEFAULT, -1 };


static void cur_obj_despawn_all_with_beh(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
        ) {
            obj->activeFlags = 0;
        }

        obj = (struct Object *) obj->header.next;
    }
}

struct SslSpawnDesc
{
    ModelID16 model;
    const BehaviorScript* behavior;
    int count;
    float z;
};

static const struct SslSpawnDesc kSslSpawns[] = {
    { MODEL_GOOMBA, bhvGoomba, 55, -350.f },
    { MODEL_KOOPA_WITHOUT_SHELL, bhvKoopa, 25, -350.f },
    { MODEL_AMP, bhvCirclingAmp, 33, -120.f },
};

static uint8_t sSslOrder[] = { 0, 1, 2 };

struct SslMults
{
    char x; char z;
};

static const struct SslMults kSslMults[] = {
    { -1, 1 },
    { -1, -1 },
    { 1, -1 },
};

void bhv_ssl_loop()
{
    if (!gMarioStates->floor)
        return;

    if (kSslFloors[o->oAction] == gMarioStates->floor->type)
    {
        if (0 == o->oAction)
        {
            for (unsigned i = 0; i < sizeof(sSslOrder); i++)
            {
                int j = random_u16() % 3;
                int tmp = sSslOrder[i];
                sSslOrder[i] = sSslOrder[j];
                sSslOrder[j] = tmp;
            }
        }

        for (unsigned i = 0; i < sizeof(sSslOrder); i++)
        {
            cur_obj_despawn_all_with_beh(kSslSpawns[i].behavior);
        }

        const struct SslSpawnDesc* desc = &kSslSpawns[sSslOrder[o->oAction]];
        for (int i = 0; i < desc->count; i++)
        {
            struct Object* obj = spawn_object(o, desc->model, desc->behavior);
            obj->oPosX = kSslMults[o->oAction].x * (500.f + random_float() * 3000.f);
            obj->oPosY = desc->z;
            obj->oPosZ = kSslMults[o->oAction].z * (500.f + random_float() * 3000.f);
        }

        o->oAction++;
    }
}
