static const u8 kSslFloors[] = { SURFACE_HARD, SURFACE_HARD_NOT_SLIPPERY, SURFACE_NOISE_DEFAULT, SURFACE_ICE, SURFACE_NOISE_DEFAULT, SURFACE_HARD_NOT_SLIPPERY, -1 };

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

    { MODEL_SSL_PLANK, bhvSslPlank, 50, 100.f },
    { MODEL_SSL_SQUARE, bhvSslSquare1, 50, -10.f },
    { MODEL_SSL_SQUARE, bhvSslSquare2, 50, -10.f },
};

static uint8_t sSslOrder[] = { 0, 1, 2, 3, 4, 5 };

struct SslMults
{
    char x; char z;
};

static const struct SslMults kSslMults[] = {
    { -1, 1 },
    { -1, -1 },
    { 1, -1 },
    
    { 1, -1 },
    { -1, -1 },
    { -1, 1 },
};

void bhv_ssl_loop()
{
    if (!gMarioStates->floor)
        return;

    if (kSslFloors[o->oAction] == gMarioStates->floor->type)
    {
        if (0 == o->oAction)
        {
            shuffle_u8(sSslOrder, 3);
            shuffle_u8(sSslOrder + 3, 3);
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

        if (SURFACE_ICE == gMarioStates->floor->type)
        {
            f32 d;
            struct Object* star = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
            star->oPosX = 789.f;
            star->oPosY = 100.f;
            star->oPosZ = 3136.f;
            o->oPosX = gMarioStates->pos[0];
            o->oPosY = gMarioStates->pos[1];
            o->oPosZ = gMarioStates->pos[2];
            cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
        }
    }
}

void bhv_ssl_plank_init()
{
    o->oFaceAngleYaw = random_u16();
    o->oFaceAnglePitch = random_u16();
}

void bhv_ssl_plank_loop()
{
    o->oFaceAnglePitch += 0x129;
}

void bhv_ssl_square1_init()
{
    o->oForwardVel = 5.f;
    o->oFaceAngleYaw = random_u16();
    obj_scale_xyz(o, 0.7f, 1.f, 0.7f);
}

static void ssl_wrap(f32* v)
{
    f32 sign = *v < 0.f ? -1.f : 1.f;
    f32 abs = absf(*v);

    if (abs > 3700.f)
    {
        abs -= 3300.f;
    }

    if (abs < 300.f)
    {
        abs += 3300.f;
    }

    *v = sign * abs;
}

void bhv_ssl_square1_loop()
{
    o->oPosX += o->oForwardVel * coss(o->oFaceAngleYaw);
    o->oPosZ += o->oForwardVel * sins(o->oFaceAngleYaw);
    ssl_wrap(&o->oPosX);
    ssl_wrap(&o->oPosZ);
}

void bhv_ssl_square2_loop()
{
    obj_scale_xyz(o, (1.1f + sins(o->oTimer * 0x168)) / 2.f, 1.f, (1.1f + coss(o->oTimer * 0x168)) / 2.f);
}
