#define oRrCtlPrevCombined oF4

void bhv_rr_ctl_init()
{

}

struct QuadrantDesc{ uint8_t x, z; };
// remove quad { 1, 1 } and { 2, 2 }. initial one is { 2, 1 }
static struct QuadrantDesc sSegmentsOrder[] = { { 0, 0 }, { 0, 2 }, { 1, 0 }, { 1, 2 }, { 2, 0 }, { 0, 1  } };

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
}
