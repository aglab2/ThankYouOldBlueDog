#define oRrCtlPrevCombined oF4
#define oRrBobCtrlCurr oObjF8
#define oRrBobCtrlNext oObjFC
#define oRrCtlProgress o100

void bhv_rr_ctl_init()
{
    o->oRrCtlPrevCombined = 0;

    f32 d;
    o->oRrBobCtrlCurr = cur_obj_find_nearest_object_with_behavior(bhvRrCube, &d);
    o->oRrBobCtrlCurr->oOpacity = 255;
    o->oRrBobCtrlNext = NULL;
    o->oRrCtlProgress = 0;

    o->oPosX = o->oRrBobCtrlCurr->oPosX;
    o->oPosY = o->oRrBobCtrlCurr->oPosY;
    o->oPosZ = o->oRrBobCtrlCurr->oPosZ;
}

struct QuadrantDesc{ uint8_t x, z; };
// remove quad { 1, 1 } and { 2, 2 }. initial one is { 2, 1 }
static struct QuadrantDesc sSegmentsOrder[] = { { 0, 0 }, { 0, 2 }, { 1, 0 }, { 1, 2 }, { 2, 0 }, { 0, 1  } };

static void rr_cubes_ctl_loop()
{
    switch (o->oAction)
    {
        case 0:
        {
            if (gMarioObject->platform == o->oRrBobCtrlCurr)
            {
                o->oPosX -= 500.f;
                o->oRrBobCtrlNext = spawn_object(o, MODEL_RR_CUBE, bhvRrCube);
                o->oRrBobCtrlNext->oPosZ += random_f32_around_zero(1000.f);
                o->oRrBobCtrlNext->oOpacity = 0;
                o->oRrBobCtrlNext->oFaceAngleYaw   = random_u16();
                o->oRrBobCtrlNext->oFaceAnglePitch = random_u16();
                o->oRrBobCtrlNext->oFaceAngleRoll  = random_u16();
                o->oAction = 1;
            }
            break;
        }
        case 1:
        {
            o->oRrBobCtrlCurr->oOpacity -= 5;
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

        gMirrorVCAmount -= 5;
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

void bhv_rr_ctl_loop()
{
    int curSegmentX = CLAMP((int) ((gMarioStates->pos[0] + 15000.f) / 10000.f), 0, 2);
    int curSegmentZ = CLAMP((int) ((gMarioStates->pos[2] + 15000.f) / 10000.f), 0, 2);

    print_text_fmt_int(20, 20, "X %d", curSegmentX);
    print_text_fmt_int(20, 40, "Z %d", curSegmentZ);
    if (2 == curSegmentX && 0 == curSegmentZ)
    {
        // scramble the randomness a bit :)
        tinymt32_init(&gGlobalRandomState, tinymt32_generate_u32(&gGlobalRandomState) ^ (*(u32*) &gMarioStates->controller->rawStickX));
        tinymt32_init(&gGlobalRandomState, tinymt32_generate_u32(&gGlobalRandomState) ^ (*(u32*) &gMarioStates->controller->buttonDown));
        if (gMarioStates->floor && gMarioStates->floor->type == SURFACE_TTM_VINES)
        {
            // randomize order of stuff in sSegmentsOrder
            for (int i = 0; i < sizeof(sSegmentsOrder) / sizeof(*sSegmentsOrder); i++)
            {
                int j = tinymt32_generate_u32(&gGlobalRandomState) % (sizeof(sSegmentsOrder) / sizeof(*sSegmentsOrder));
                struct QuadrantDesc tmp = sSegmentsOrder[i];
                sSegmentsOrder[i] = sSegmentsOrder[j];
                sSegmentsOrder[j] = tmp;
            }
            // let the game roll...
        }
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
        o->oMoveAngleYaw = -0x4000;
        if (o->oTimer > 100)
        {
            o->oGravity = -2.f;
        }
    }

    cur_obj_move_using_fvel_and_gravity();
}
