// Up water

#include "engine/surface_collision.h"

extern u8 gDisableGravity;

void bhv_hmc_ctl_loop()
{
    gDisableGravity = 0;
    if (gMarioStates->controller->buttonPressed & Z_TRIG)
    {
        if (o->oAction == 0)
            play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
        
        o->oAction = 1;
    }
    else
    {
        o->oAction = 0;
    }
    gMarioStates->controller->buttonDown &= ~Z_TRIG;
    gMarioStates->controller->buttonPressed &= ~Z_TRIG;

    gCollisionFlags |= COLLISION_FLAG_WATER;

    struct Surface* floor = NULL;
    f32 floorHeight = find_floor(gMarioStates->pos[0], gMarioStates->pos[1], gMarioStates->pos[2], &floor);
    if (floorHeight == FLOOR_LOWER_LIMIT)
    {    
        gCollisionFlags &= ~COLLISION_FLAG_WATER;
        return;
    }

    struct Surface* ceil = NULL;
    f32 ceilHeight = find_ceil(gMarioStates->pos[0], floorHeight, gMarioStates->pos[2], &ceil);
    gCollisionFlags &= ~COLLISION_FLAG_WATER;

    if (floorHeight - 40.f < gMarioStates->pos[1] && gMarioStates->pos[1] < ceilHeight)
    {
        if (gMarioStates->controller->buttonPressed & B_BUTTON)
        {
            if (o->oF4 == 0)
                play_sound(SOUND_OBJ_MIPS_RABBIT_WATER, gGlobalSoundSource);
            
            o->oF4 = 1;
        }
        else
        {
            o->oF4 = 0;
        }

        gMarioStates->controller->buttonDown &= ~B_BUTTON;
        gMarioStates->controller->buttonPressed &= ~B_BUTTON;
        gDisableGravity = 1;
        gMarioStates->action = ACT_JUMP;
        gMarioStates->vel[1] += 4.f;
        if (gMarioStates->vel[1] > 60.f)
            gMarioStates->vel[1] = 60.f;
    }
}
