#include "seq_ids.h"

#define oRrCtlPrevCombined oF4
#define oRrBobCtrlCurr oObjF8
#define oRrBobCtrlNext oObjFC
#define oRrCtlProgress o100
#define oRrWdwCtlWasOnPlatformBefore o104
#define oRrBobCtlLimitCubes o108
#define oRrWdwDeathTime o10C
#define oRrReactionTime o110
#define oRrHmcWaterSfx o110

extern s16 gCameraMovementFlags;
u8 gGoMode = 0;

extern s16 s8DirModeYawOffset;

static void rr_obj_despawn_all_flames()
{
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvFlame);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;
    int amount = 0;

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

extern struct Pos kRrCoinsLocations[];
void bhv_rr_ctl_init()
{
    if (!gIsHM)
    {
        struct Pos* positions = segmented_to_virtual(kRrCoinsLocations);
        for (int i = 13; i < 18; i++)
        {
            struct Object* coin = spawn_object(o, MODEL_YELLOW_COIN, bhvYellowCoin);
            coin->oPosX = positions[i].x;
            coin->oPosY = positions[i].y;
            coin->oPosZ = positions[i].z;
        }
    }

    o->oRrCtlPrevCombined = 0;

    f32 d;
    o->oRrBobCtrlCurr = cur_obj_find_nearest_object_with_behavior(bhvRrCube, &d);
    o->oRrBobCtrlCurr->oOpacity = 255;
    o->oRrBobCtrlNext = NULL;
    o->oRrCtlProgress = 0;

    o->oPosX = o->oRrBobCtrlCurr->oPosX;
    o->oPosY = o->oRrBobCtrlCurr->oPosY;
    o->oPosZ = o->oRrBobCtrlCurr->oPosZ;

    o->oRrBobCtlLimitCubes = 5;

    gGoMode = 0;
    if (!gIsHM)
    {
        rr_obj_despawn_all_flames();
    }
    else
    {
        o->oRrReactionTime = 30;
        o->oRrWdwDeathTime = 90;
        o->parentObj = spawn_object(o, MODEL_STAR, bhvStar);
        f32 d;

        f32 x = o->oPosX;
        f32 y = o->oPosY;
        f32 z = o->oPosZ;
        o->oPosX = -9389;
        o->oPosY = 85l;
        o->oPosZ = 12933;

        struct Object* start = cur_obj_find_nearest_object_with_behavior(bhvRrStart, &d);
        o->parentObj->oPosX = o->parentObj->oHomeX = start->oPosX + 300.f;
        o->parentObj->oPosY = o->parentObj->oHomeY = start->oPosY + 50.f;
        o->parentObj->oPosZ = o->parentObj->oHomeZ = start->oPosZ;

        o->oPosX = x;
        o->oPosY = y;
        o->oPosZ = z;
    }
}

Vec3f sLastFailPosition;

typedef union
{
    struct
    {
        u8 x, z;
    };
    // i need alignment for shuffling
    u16 align;
} QuadrantDesc;

static QuadrantDesc sSegmentsOrder[] = { { 0, 0 }, { 0, 2 }, { 2, 2 }, { 1, 2 }, { 2, 0 }, { 0, 1 }, { 2, 1 }, { 1, 1 } };

static void rr_cubes_ctl_loop()
{
    switch (o->oAction)
    {
        case 0:
        {
            if (o->oRrBobCtrlCurr && gMarioObject->platform == o->oRrBobCtrlCurr)
            {
                o->oPosX -= 700.f;
                if (o->oRrBobCtlLimitCubes)
                {
                    o->oRrBobCtlLimitCubes--;
                    o->oRrBobCtrlNext = spawn_object(o, MODEL_RR_CUBE, bhvRrCube);
                    o->oRrBobCtrlNext->oPosZ += random_f32_around_zero(1000.f);
                    o->oRrBobCtrlNext->oOpacity = 0;
                    o->oRrBobCtrlNext->oFaceAngleYaw   = 0x1000 * random_u16();
                    o->oRrBobCtrlNext->oFaceAnglePitch = 0x1000 * random_u16();
                    o->oRrBobCtrlNext->oFaceAngleRoll  = 0x1000 * random_u16();
                }
                else
                {
                    o->oRrBobCtrlNext = NULL;
                }
                o->oAction = 1;
            }
            break;
        }
        case 1:
        {
            o->oRrBobCtrlCurr->oOpacity -= 5;
            if (o->oRrBobCtrlNext)
                o->oRrBobCtrlNext->oOpacity += 5;

            if (o->oRrBobCtrlCurr->oOpacity == 0)
            {
                o->oRrBobCtrlCurr->activeFlags = 0;
                o->oRrBobCtrlCurr = o->oRrBobCtrlNext;
                o->oRrBobCtrlNext = NULL;
                o->oAction = 0;
            }
            break;
        }
    }
}

void rr_mirror_mario_ctl_loop()
{
    if (!gMarioState->floor)
        return;

    if (gMarioState->floor->type == SURFACE_HARD_NOT_SLIPPERY || gMarioState->floor->type == SURFACE_HANGABLE)
    {
        gMirrorTrigger = 1;
        gMarioStates->flags |= MARIO_VANISH_CAP;
        if (gMarioState->floor->type == SURFACE_HARD_NOT_SLIPPERY)
        {
            gMirrorOffset[0] = -741.38f;
            gMirrorOffset[2] = 741.38f;
        }
        if (gMarioState->floor->type == SURFACE_HANGABLE)
        {
            gMirrorOffset[0] = -741.38f;
            gMirrorOffset[2] = -741.38f;
        }

        gMirrorVCAmount -= gIsHM ? 17 : 5;
        if (0 == gMirrorVCAmount)
        {
            gMarioStates->pos[0] += gMirrorOffset[0];
            gMarioStates->pos[1] += gMirrorOffset[1];
            gMarioStates->pos[2] += gMirrorOffset[2];
            gMirrorVCAmount = 255;
        }
    }
    else
    {
        gMirrorTrigger = 0;
        if (gMirrorVCAmount < 240)
        {
            gMirrorVCAmount += 15;
        }
        else
        {
            gMirrorVCAmount = 255;
            gMarioStates->flags &= ~MARIO_VANISH_CAP;
        }
    }
}

void rr_water_ctl_loop()
{
    gDisableGravity = 0;
    gCollisionFlags |= COLLISION_FLAG_WATER;
    int gm0 = gIsGravityFlipped;
    int gm1 = gGravityMode;
    gIsGravityFlipped = 0;
    gGravityMode = 0;

    f32 marioY = gm0 ? (8825.f - gMarioStates->pos[1]) : gMarioStates->pos[1];

    struct Surface* floor = NULL;
    f32 floorHeight = find_floor(gMarioStates->pos[0], marioY, gMarioStates->pos[2], &floor);
    if (floorHeight == FLOOR_LOWER_LIMIT)
    {    
        gIsGravityFlipped = gm0;
        gGravityMode = gm1;
        gCollisionFlags &= ~COLLISION_FLAG_WATER;
        if (gIsHM)
            set_gravity(0);

        return;
    }

    struct Surface* ceil = NULL;
    f32 ceilHeight = find_ceil(gMarioStates->pos[0], floorHeight, gMarioStates->pos[2], &ceil);

    gIsGravityFlipped = gm0;
    gGravityMode = gm1;
    gCollisionFlags &= ~COLLISION_FLAG_WATER;

    s32 grav = 0;
    if (floorHeight - 50.f < marioY && marioY < ceilHeight)
    {
        if (!gIsHM)
        {
            if (gMarioStates->controller->buttonPressed & B_BUTTON)
            {
                if (o->oRrHmcWaterSfx == 0)
                    play_sound(SOUND_OBJ_MIPS_RABBIT_WATER, gGlobalSoundSource);
                
                o->oRrHmcWaterSfx = 1;
            }
            else
            {
                o->oRrHmcWaterSfx = 0;
            }

            gMarioStates->controller->buttonDown &= ~B_BUTTON;
            gMarioStates->controller->buttonPressed &= ~B_BUTTON;
            gDisableGravity = 1;
            if (gMarioStates->action != ACT_JUMP && (gMarioStates->pos[1] - gMarioStates->floorHeight) < 10.f)
            {
                gMarioStates->vel[1] = 0;
                if (gMarioStates->floor->normal.y < 0.8f)
                {
                    gMarioStates->pos[0] += 20.f * gMarioStates->floor->normal.x;
                    gMarioStates->pos[1] += 20.f * gMarioStates->floor->normal.y;
                    gMarioStates->pos[2] += 20.f * gMarioStates->floor->normal.z;
                }
            }
            gMarioStates->action = ACT_JUMP;

            f32 raisevel = 4.f;
            gMarioStates->vel[1] += raisevel;

            f32 maxvel = 60.f;
            if (gMarioStates->vel[1] > maxvel)
                gMarioStates->vel[1] = maxvel;
        }
        else
        {
            grav = 1;
        }
    }

    if (gIsHM)
        set_gravity(grav);
}

static int toSegmentIndex(f32 pos)
{
    return CLAMP((int) ((pos + 15000.f) / 10000.f), 0, 2);
}

static struct Object *cur_obj_find_spawner_in_section(const BehaviorScript *behavior, int x, int z) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;
    struct Object *closestObj = NULL;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
        ) {
            int objSegmentX = toSegmentIndex(obj->oPosX);
            int objSegmentZ = toSegmentIndex(obj->oPosZ);
            if (objSegmentX == x && objSegmentZ == z)
            {
                closestObj = obj;
                break;
            }
        }

        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}

void bhv_rr_cube_init()
{
    o->oF4  = random_u16() % 6;
}

void bhv_rr_cube_loop()
{
    switch (o->oF4)
    {
        case 0:
            o->oFaceAngleYaw += 0x30;
            break;
        case 1:
            o->oFaceAnglePitch += 0x30;
            break;
        case 2:
            o->oFaceAngleRoll += 0x30;
            break;
        case 3:
            o->oFaceAngleYaw -= 0x30;
            break;
        case 4:
            o->oFaceAnglePitch -= 0x30;
            break;
        case 5:
            o->oFaceAngleRoll -= 0x30;
            break;
    }
}

void bhv_rr_ctl_loop()
{
#if 0
    record_on_frame();
#endif

    int curSegmentX = toSegmentIndex(gMarioStates->pos[0]);
    int curSegmentZ = toSegmentIndex(gMarioStates->pos[2]);

    // print_text_fmt_int(20, 20, "X %d", curSegmentX);
    // print_text_fmt_int(20, 40, "Z %d", curSegmentZ);
    if (1 == curSegmentX && 0 == curSegmentZ)
    {
        // scramble the randomness a bit :)
        tinymt32_init(&gGlobalRandomState, tinymt32_generate_u32(&gGlobalRandomState) ^ (*(u32*) &gMarioStates->controller->rawStickX));
        tinymt32_init(&gGlobalRandomState, tinymt32_generate_u32(&gGlobalRandomState) ^ (*(u32*) &gMarioStates->controller->buttonDown));
    }

    if (gIsHM)
    {
        if (curSegmentX == 0 && curSegmentZ == 2)
        {
            print_death_timer_left(o->oRrWdwDeathTime);
            o->parentObj->oIntangibleTimer = -1;
            
            f32 dx = o->parentObj->oPosX - gMarioStates->pos[0];
            f32 dy = o->parentObj->oPosY - (gMarioStates->pos[1] + 80.f);
            f32 dz = o->parentObj->oPosZ - gMarioStates->pos[2];
            f32 d = dx * dx + dy * dy + dz * dz;
            if (d < 23000.f)
            {
                f32 dcx = o->parentObj->oPosX - o->parentObj->oHomeX;
                f32 dcz = o->parentObj->oPosZ - o->parentObj->oHomeZ;
                f32 curMag = sqrtf(dx * dx + dz * dz);
                f32 curAngle = atan2s(dz, dx);

                o->parentObj->oPosX = (curMag + 150.f) * sins(curAngle + 0x100) + o->parentObj->oHomeX;
                o->parentObj->oPosZ = (curMag + 150.f) * coss(curAngle + 0x100) + o->parentObj->oHomeZ;
                o->oRrWdwDeathTime += 30;
                play_sound(SOUND_GENERAL_COIN_SPURT, gMarioStates->marioObj->header.gfx.cameraToObject);
            }

            if (o->oRrWdwDeathTime)
            {
                o->oRrWdwDeathTime--;
                if (0 == o->oRrWdwDeathTime)
                {
                    gMarioStates->action = 0;
                }
            }
        }

        if (2 == curSegmentX && 1 == curSegmentZ)
        {
            if (o->oRrReactionTime)
            {
               o->oRrReactionTime--;
            }
            else
            {
                gFizzle = CLAMP(gFizzle + 1, 0, 255);
            }
        }
        else
        {
            gFizzle = 0;
        }
    }

    if (1 == curSegmentX && 1 == curSegmentZ)
    {
        if (!gGoMode)
        {
            f32 marioY = gIsGravityFlipped ? (8825.f - gMarioStates->pos[1]) : gMarioStates->pos[1];
            if ((!gIsHM || gIsGravityFlipped) && marioY > 2700.f)
            {
                gGoMode = 1;
                o->oHomeX = gMarioStates->pos[0];
                o->oHomeY = gMarioStates->pos[1];
                o->oHomeZ = gMarioStates->pos[2];
                set_cam_angle(2);
                gCameraMovementFlags |= CAM_MOVE_ZOOMED_OUT;
                seq_player_fade_out(0, 200);
                seq_player_play_sequence(SEQ_PLAYER_ENV, SEQ_EVENT_WEGF, 0);
            }
        }

        if (gGoMode)
        {
            gMarioStates->pos[0] = o->oHomeX;
            gMarioStates->pos[1] = o->oHomeY;
            o->oHomeY += gIsGravityFlipped ? -11.f : 11.f;
            gMarioStates->pos[2] = o->oHomeZ;

            gMarioStates->controller->rawStickX = 0;
            gMarioStates->controller->rawStickY = 0;
            gMarioStates->controller->stickX = 0;
            gMarioStates->controller->stickY = 0;
            gMarioStates->controller->stickMag = 0;
            gMarioStates->controller->buttonDown &= ~(B_BUTTON | A_BUTTON | Z_TRIG | R_TRIG | L_TRIG | START_BUTTON);
            gMarioStates->controller->buttonPressed &= ~(B_BUTTON | A_BUTTON | Z_TRIG | R_TRIG | L_TRIG | START_BUTTON);
            gMarioStates->controller->buttonReleased &= ~(B_BUTTON | A_BUTTON | Z_TRIG | R_TRIG | L_TRIG | START_BUTTON);

            f32 marioY = gIsGravityFlipped ? (8825.f - gMarioStates->pos[1]) : gMarioStates->pos[1];
            if (1 == gGoMode && marioY > 11500.f)
            {
                save_file_collect_star_or_key(0, 0);
                gMarioStates->numStars =
                    save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);
                gMarioStates->usedObj = o;
                SET_BPARAM2(o->oBehParams, 0xa);
                level_trigger_warp(gMarioStates, WARP_OP_TELEPORT);
                gGoMode = 2;
                o->oTimer = 0;
            }

            if (2 == gGoMode)
            {
                if (o->oTimer > 260)
                    set_gravity(0);
            }
            return;
        }
    }

    if (gMarioStates->floor && gMarioStates->floor->type == SURFACE_TTM_VINES && (gMarioStates->pos[1] - gMarioStates->floorHeight) < 700.f)
    {    
        if (1 == curSegmentX && 0 == curSegmentZ)
        {
            shuffle_u16((u16*) sSegmentsOrder, (sizeof(sSegmentsOrder) / sizeof(*sSegmentsOrder)) - 1);
            int failSegmentX = toSegmentIndex(sLastFailPosition[0]);
            int failSegmentZ = toSegmentIndex(sLastFailPosition[2]);
            for (int i = 0; i < sizeof(sSegmentsOrder) / sizeof(*sSegmentsOrder) - 1; i++)
            {
                if (sSegmentsOrder[i].x == failSegmentX && sSegmentsOrder[i].z == failSegmentZ)
                {
                    QuadrantDesc tmp = sSegmentsOrder[i];
                    sSegmentsOrder[i] = sSegmentsOrder[0];
                    sSegmentsOrder[0] = tmp;
                    break;
                }
            }
        }

        const QuadrantDesc* desc = &sSegmentsOrder[o->oRrCtlProgress];
#if 1
        const struct Object* start = cur_obj_find_spawner_in_section(bhvRrStart, desc->x, desc->z);
#else
        const struct Object* start = cur_obj_find_spawner_in_section(bhvRrStart, 2, 2);
#endif
        o->oRrCtlProgress++;

        gMarioStates->pos[0] = start->oPosX;
        gMarioStates->pos[1] = start->oPosY;
        gMarioStates->pos[2] = start->oPosZ;
        gMarioStates->faceAngle[1] = start->oFaceAngleYaw;
        reset_camera(gCamera);
        s8DirModeYawOffset = 0xe000 & (gMarioStates->faceAngle[1] + 0x9000);
        {
            struct Object *orangeNumber = spawn_object_relative(o->oRrCtlProgress, 28.f, 0, 0, start, MODEL_NUMBER, bhvOrangeNumber);
            orangeNumber->oPosY += 25.0f;
            orangeNumber->oOrangeNumberOffset = 28.f;
            orangeNumber->oHomeX = start->oPosX;
            orangeNumber->oHomeZ = start->oPosZ;
        }

        play_sound(SOUND_MENU_COLLECT_RED_COIN + (o->oRrCtlProgress << 16), gGlobalSoundSource);
    }

    if (1 == curSegmentX && 2 == curSegmentZ)
    {
        rr_cubes_ctl_loop();
    }
    
    if (0 == curSegmentX && 0 == curSegmentZ)
    {
        rr_mirror_mario_ctl_loop();
    }
    else
    {
        gMirrorTrigger = 0;
        gMirrorVCAmount = 255;
        gMirrorOffset[0] = 0.f;
        gMirrorOffset[1] = 0.f;
        gMirrorOffset[2] = 0.f;
    }

    if (1 == curSegmentX && 1 == curSegmentZ)
    {
        rr_water_ctl_loop();
    }
    else
    {
        if (!gIsHM)
            gDisableGravity = 0;
    }
}

void rr_move_ctl_init()
{
    o->oFaceAngleYaw = -0x4000;
    o->oMoveAngleYaw = -0x4000;
}

void rr_move_ctl_loop()
{
    o->oCollisionDistance = 10000.f;
    if (0 == o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            o->oAction = 1;
            o->oForwardVel = 25.0f;
        }
    }
    else
    {
        if (o->oTimer > 100)
        {
            o->oGravity = -2.f;
        }
    }

    o->oFaceAngleYaw = o->oMoveAngleYaw = -0x4000 + 0x4000 * obj_count_opened_gate_switches();
    if (o->oPosY < -30000.f)
    {
        o->activeFlags = 0;
    }

    cur_obj_move_using_fvel_and_gravity();
}

#define oRrMoveCtlPurplesObjects oObjF4

void rr_move_ctl_purples_init()
{
    if (!gIsHM)
    {
        o->activeFlags = 0;
        return;
    }

    struct Object** purples = &o->oObjF4;
    for (int i = 0; i < 3; i++)
    {
        purples[i] = spawn_object(o, MODEL_PURPLE_SWITCH, bhvFloorSwitchGrills);
    }
}

void rr_move_ctl_purples_loop()
{
    if (!gIsHM)
    {
        o->activeFlags = 0;
        return;
    }

    struct Object** purples = &o->oObjF4;
    int curSegmentX = toSegmentIndex(gMarioStates->pos[0]);
    int curSegmentZ = toSegmentIndex(gMarioStates->pos[2]);
    if (curSegmentX != 2 || curSegmentZ != 0)
    {
        purples[0]->oFaceAngleYaw = 0;
        return;
    }

    purples[0]->oFaceAngleYaw += 0x169;
    purples[0]->oPosX = o->oPosX + 500.f * sins(purples[0]->oFaceAngleYaw);
    purples[0]->oPosZ = o->oPosZ + 500.f * coss(purples[0]->oFaceAngleYaw);

    purples[1]->oPosX = o->oPosX - 700.f;
    purples[1]->oPosZ = o->oPosZ + 1000.f * sins(-purples[0]->oFaceAngleYaw);

    purples[2]->oPosX = o->oPosX;
    purples[2]->oPosZ = o->oPosZ + 1000.f * coss(purples[0]->oFaceAngleYaw);
}

void rr_rotat_init()
{
    o->oDrawingDistance = 10000.f;
    obj_scale(o, 0.4f);
}

extern const Collision rr_rotat_collision[];
extern const Collision rr_rotat_death_collision[];
void rr_rotat_loop()
{
    o->oFaceAngleYaw += 0x34;
    o->oPosX = o->oHomeX + 700.f * sins(o->oFaceAngleYaw);
    o->oPosZ = o->oHomeZ + 700.f * coss(o->oFaceAngleYaw);

    if (gIsHM)
    {
        o->oFaceAnglePitch += 0x66;
    }

    if (o->oOpacity < 10)
    {
        obj_set_collision_data(o, rr_rotat_death_collision);
    }
    else
    {
        obj_set_collision_data(o, rr_rotat_collision);
    }

    if (0 == o->oAction)
    {
        if (255 == o->oOpacity && gMarioObject->platform == o)
        {
            o->oAction = 1;
        }
    }
    else if (1 == o->oAction)
    {
        if (o->oOpacity > 8)
        {
            o->oOpacity -= 7;
        }
        else
        {
            o->oOpacity = 0;
            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
        if (o->oTimer > 60)
        {
            int amt = o->oOpacity + 50;
            o->oOpacity = CLAMP(amt, 0, 255);
            if (o->oOpacity == 255)
            {
                o->oAction = 0;
            }
        }
    }
}

extern const BehaviorScript bhvRrRotat[];
void rr_rotat_ctl_init()
{
    for (int i = 0; i < 8; i++)
    {
        struct Object* obj = spawn_object(o, MODEL_RR_ROTAT, bhvRrRotat);
        obj->oFaceAngleYaw = i * (0x10000 / 8);
        obj->oPosX = o->oPosX + 700.f * sins(obj->oFaceAngleYaw);
        obj->oPosZ = o->oPosZ + 700.f * coss(obj->oFaceAngleYaw);

        obj->oHomeX = o->oPosX;
        obj->oHomeZ = o->oPosZ;

        obj->oOpacity = i % 2 ? 0 : 255;
    }
}

extern const Collision rr_jump_0_collision[];
extern const Collision rr_jump_1_collision[];
void rr_jump_init()
{
    cur_obj_set_model(MODEL_RR_JUMP_0);
    obj_set_collision_data(o, rr_jump_0_collision);
    o->oRrWdwCtlWasOnPlatformBefore = 0;
}

static void rr_wdw_switch()
{
    o->oAction = !o->oAction;
    if (o->oAction)
    {
        cur_obj_set_model(MODEL_RR_JUMP_1);
        obj_set_collision_data(o, rr_jump_1_collision);
    }
    else
    {
        cur_obj_set_model(MODEL_RR_JUMP_0);
        obj_set_collision_data(o, rr_jump_0_collision);
    }
}

void rr_jump_loop()
{
    int onPlatform = gMarioObject->platform == o;
    if (o->oRrWdwCtlWasOnPlatformBefore && !onPlatform)
    {
        rr_wdw_switch();
    }
    o->oRrWdwCtlWasOnPlatformBefore = onPlatform;
}

void bhv_rr_flipper_loop()
{
    if (12000.f < gMarioStates->pos[2] && gMarioStates->pos[2] < 14000.f && 11000.f < gMarioStates->pos[0] && gMarioStates->pos[0] < 14000.f)
        gMarioStates->pos[2] = o->oPosZ;

    if (gIsHM)
    {
        if (o->oBehParams2ndByte == 0)
        {
            bhv_ccm_flipper_up_impl(0.f, 1900.f);
        }
        else
        {
            bhv_ccm_flipper_up_impl(1900.f, 0.f);
        }
    }
    else
    {
        bhv_ccm_flipper_loop();
    }
}
