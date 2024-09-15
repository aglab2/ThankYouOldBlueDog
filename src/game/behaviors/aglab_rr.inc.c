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
}
