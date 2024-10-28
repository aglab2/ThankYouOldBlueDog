#include "buffers/buffers.h"

// 72
#define oLll72BaseDist oFloatF4
#define oLll72BaseAngle oF8

extern u8 gFizzle;

void bhv_lll_72_init()
{
    gMirrorVCAmount = 255;
    o->oLll72BaseDist = sqrtf(o->oPosX * o->oPosX + o->oPosZ * o->oPosZ);
    o->oF8 = atan2s(o->oPosZ, o->oPosX);
}

void bhv_lll_72_loop()
{
    if (gMarioStates->action == ACT_STAR_DANCE_WATER)
        return;

    if (!gMarioStates->action)
        return;

    if (0 == o->oAction)
    {
        if (gMarioStates->floor && gMarioStates->floor->type == SURFACE_HARD_NOT_SLIPPERY)
        {
            o->oAction = 1;
        }
    }
    else
    {
        f32 mult = gSaveBuffer.files[gCurrSaveFileNum - 1][0].tampers ? 1.05f : 1.3f;
        s16 angle = o->oLll72BaseAngle - 30 * o->oTimer * mult;
        f32 dist = o->oLll72BaseDist - 1000.f * (1 - coss(o->oTimer * 0xa2 * mult));
        o->oPosX = dist * sins(angle);
        o->oPosZ = dist * coss(angle);
    }

    if (gMarioStates->floor && (gMarioStates->floor->type == SURFACE_NOT_SLIPPERY || gMarioStates->floor->type == SURFACE_HARD_NOT_SLIPPERY))
    {
        int amt = CLAMP(gMirrorVCAmount + 2, 0, 255);
        gMirrorVCAmount = amt;
        if (amt == 255)
            gMarioStates->flags &= ~MARIO_VANISH_CAP;
    }
    else
    {
        cur_obj_play_sound_2(SOUND_MOVING_LAVA_BURN);
        int fizzlePower = gIsHM ? 14 : 10;
        int amt = CLAMP(gMirrorVCAmount - fizzlePower, 0, 255);
        gMirrorVCAmount = amt;
        gMarioStates->flags |= MARIO_VANISH_CAP;
        if (amt == 0)
            gMarioStates->action = 0;
    }
    
    if (gIsHM)
    {
        gFizzle = CLAMP(1.2f * (255 - gMirrorVCAmount), 0, 255);
        gMarioStates->flags &= ~MARIO_VANISH_CAP;
    }
}
