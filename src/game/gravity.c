#include "game/level_update.h"
#include "game/object_list_processor.h"

u8 sDeferGravSwap = 0;
extern u32 gIsGravityFlipped;
void set_gravity(u32 grav)
{
    if (grav == gIsGravityFlipped)
        return;

    gIsGravityFlipped = grav;
            
    if (gIsGravityFlipped)
        play_sound(SOUND_MENU_CAMERA_ZOOM_IN, gMarioObject->header.gfx.pos);
    else
        play_sound(SOUND_MENU_CAMERA_ZOOM_OUT, gMarioObject->header.gfx.pos);

    gMarioState->pos[1] = 8825.f - gMarioState->pos[1]; // Transform position. The extra 165 is due to Mario's visual model.
    if ((gMarioState->action == ACT_CRAZY_BOX_BOUNCE) || (gMarioState->action == ACT_SHOT_FROM_CANNON))
        gMarioState->pos[1] += 165.f;
    else if ((gMarioState->action == ACT_DIVE) || (gMarioState->action == ACT_FLYING))
        gMarioState->pos[1] += 65.f;

    gMarioState->vel[1] = -gMarioState->vel[1]; // Flip velocity
    gMarioState->peakHeight = 9000.f - gMarioState->peakHeight; // For fall damage
    gMarioObject->hitboxDownOffset = (gIsGravityFlipped ? 160.f : 0.f); // Adjust hitbox when upside down
}
