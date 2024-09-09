#include "savestate.h"

#include "binary.h"
#include "cfg.h"
#include "text_manager.h"

#include "game/area.h"
#include "game/camera.h"
#include "game/print.h"
#include "game/level_update.h"
#include "libc/string.h"

void set_play_mode(s16 playMode);

#ifdef BINARY
#define Hacktice_gState ((State*) 0x80026000)
#else
#define Hacktice_gState ((State*) 0x80525800)
#endif

#ifdef BINARY
static u8* _hackticeStateDataStart = (u8*) &gMarioStates;
static u8* _hackticeStateDataEnd = ((u8*) &gMarioStates) + 0x26B28;
#else
extern u8 _hackticeStateDataStart0[];
extern u8 _hackticeStateDataEnd0[];
extern u8 _hackticeStateDataStart1[];
extern u8 _hackticeStateDataEnd1[];
#endif

static bool sMustSaveState = 0;
static bool sMustLoadState = 0;

extern uint32_t gSafePosAllowedFrame;

extern u32 gIsGravityFlipped;

static void resetCamera()
{
    if (CAMERA_MODE_BEHIND_MARIO  == gCamera->mode
     || CAMERA_MODE_WATER_SURFACE == gCamera->mode
     || CAMERA_MODE_INSIDE_CANNON == gCamera->mode
     || CAMERA_MODE_CLOSE         == gCamera->mode)
    {
        set_camera_mode(gMarioStates->area->camera, gMarioStates->area->camera->defMode, 1);
    }

    if (CUTSCENE_ENTER_BOWSER_ARENA != gMarioStates->area->camera->cutscene)
    {
        gMarioStates->area->camera->cutscene = 0;
    }
}

void SaveState_onNormal()
{
    if (sMustSaveState)
    {
        sMustSaveState = false;
        sMustLoadState = false;
        Hacktice_gState->area  = gCurrAreaIndex;
        Hacktice_gState->level = gCurrLevelNum;
        Hacktice_gState->flipped = gIsGravityFlipped;
        Hacktice_gState->size = sizeof(State);
        memcpy(Hacktice_gState->memory, _hackticeStateDataStart0, _hackticeStateDataEnd0 - _hackticeStateDataStart0);
        memcpy(Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0), _hackticeStateDataStart1, _hackticeStateDataEnd1 - _hackticeStateDataStart1);
    }
    else
    {
        if (sMustLoadState || (Config_action() == Config_ButtonAction_LOAD_STATE && gSafePosAllowedFrame != gGlobalTimer - 1))
        {
            sMustLoadState = false;
            if (Hacktice_gState->area == gCurrAreaIndex && Hacktice_gState->level == gCurrLevelNum)
            {
                memcpy(_hackticeStateDataStart0, Hacktice_gState->memory, _hackticeStateDataEnd0 - _hackticeStateDataStart0);
                memcpy(_hackticeStateDataStart1, Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0), _hackticeStateDataEnd1 - _hackticeStateDataStart1);
                gIsGravityFlipped = Hacktice_gState->flipped;
                resetCamera();
            }
        }
    }
}

void SaveState_onPause()
{
    if ((Config_saveStateStyle() == Config_StateSaveStyle_PAUSE  && !sMustSaveState)
     || (Config_saveStateStyle() == Config_StateSaveStyle_BUTTON && Config_action() == Config_ButtonAction_LOAD_STATE))
    {
        sMustSaveState = true;
        TextManager_addLine("STATE SET", 30);
    }
}

void SaveState_Trigger()
{
    sMustSaveState = true;
}

void SaveState_Load()
{
    sMustLoadState = true;
}