// Up water

#include "engine/surface_collision.h"

extern u8 gDisableGravity;

void bhv_hmc_ctl_loop()
{
    gDisableGravity = 0;
    gMarioStates->controller->buttonDown &= ~Z_TRIG;
    gMarioStates->controller->buttonPressed &= ~Z_TRIG;

    gCollisionFlags |= COLLISION_FLAG_WATER;

    struct Surface* floor = NULL;
    f32 floorHeight = find_floor(gMarioStates->pos[0], CELL_HEIGHT_LIMIT, gMarioStates->pos[2], &floor);
    struct Surface* ceil = NULL;
    f32 ceilHeight = find_ceil(gMarioStates->pos[0], FLOOR_LOWER_LIMIT, gMarioStates->pos[2], &ceil);

    s32 hasFloor = floor && floor->type == SURFACE_WATER;
    s32 hasCeil = ceil && ceil->type == SURFACE_WATER;
    
    // print_text_fmt_int(20, 60, "C %d", (int) ceilHeight);
    // print_text_fmt_int(20, 80, "F %d", (int) floorHeight);

    // print_text_fmt_int(20, 100, "HF %d", hasFloor);
    // print_text_fmt_int(20, 120, "HC %d", hasCeil);

    gCollisionFlags &= ~COLLISION_FLAG_WATER;

    if (!hasFloor && !hasCeil)
        return;

    if (!hasFloor)
        ceilHeight = FLOOR_LOWER_LIMIT;
    
    if (!hasCeil)
        floorHeight = CELL_HEIGHT_LIMIT;

    if (ceilHeight - 40.f < gMarioStates->pos[1] && gMarioStates->pos[1] < floorHeight)
    {
        gDisableGravity = 1;
        gMarioStates->action = ACT_JUMP;
        gMarioStates->vel[1] += 4.f;
        if (gMarioStates->vel[1] > 60.f)
            gMarioStates->vel[1] = 60.f;
    }
}
