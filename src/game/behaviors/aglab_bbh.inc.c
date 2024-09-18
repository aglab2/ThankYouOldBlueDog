#include "game/level_update.h"

extern u8 gMirrorVCAmount;
extern u8 gMirrorTrigger;
extern Vec3f gMirrorOffset;

void bhv_bbh_ctl_init()
{
    gMirrorVCAmount = 255;
    gMirrorOffset[0] = 0.f;
    gMirrorOffset[1] = 0.f;
    gMirrorOffset[2] = 0.f;
}

void bhv_bbh_ctl_loop()
{
    if (gMarioStates->action == ACT_STAR_DANCE_WATER)
    {
        gMirrorTrigger = 0;
        gMirrorVCAmount = 255;
        gMarioStates->flags &= ~MARIO_VANISH_CAP;
        return;
    }

    if (!gMarioState->floor)
        return;

    if (gMarioState->floor->type == SURFACE_TTM_VINES || gMarioState->floor->type == SURFACE_NOT_SLIPPERY || gMarioState->floor->type == SURFACE_HARD_NOT_SLIPPERY || gMarioState->floor->type == SURFACE_SWITCH)
    {
        gMirrorTrigger = 1;
        gMarioStates->flags |= MARIO_VANISH_CAP;
        if (gMarioState->floor->type == SURFACE_TTM_VINES)
            gMirrorOffset[2] = -500.f;
        if (gMarioState->floor->type == SURFACE_NOT_SLIPPERY)
            gMirrorOffset[2] = 500.f;
        if (gMarioState->floor->type == SURFACE_HARD_NOT_SLIPPERY)
            gMirrorOffset[2] = 1000.f;
        if (gMarioState->floor->type == SURFACE_SWITCH)
            gMirrorOffset[2] = -1000.f;

        gMirrorVCAmount -= 5;
        if (0 == gMirrorVCAmount)
        {
            gMarioStates->pos[0] += gMirrorOffset[0];
            gMarioStates->pos[1] += gMirrorOffset[1];
            gMarioStates->pos[2] += gMirrorOffset[2];
            gMirrorVCAmount = 255;
            o->oPosX = gMarioStates->pos[0];
            o->oPosY = gMarioStates->pos[1];
            o->oPosZ = gMarioStates->pos[2];
            cur_obj_play_sound_2(SOUND_GENERAL2_ROTATING_BLOCK_CLICK);
            // reset_camera(gCamera);
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
