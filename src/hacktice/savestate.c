#include "savestate.h"

#include "binary.h"
#include "cfg.h"
#include "text_manager.h"

#include "game/area.h"
#include "game/camera.h"
#include "game/emutest.h"
#include "game/game_init.h"
#include "game/print.h"
#include "game/level_update.h"
#include "game/object_list_processor.h"
#include "engine/math_util.h"
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

#define PROBE0 0xb3ff1000
#define PROBE1 0xbffbfff0
// This is used only for ancient emulators :)
#define PROBE2 0x90000000

static bool sProbesChecked = false;
static bool sProbesOk[3];
static bool sProbesValid[3]; 

static bool sUsedStates = false;

static bool probeValid(u32 probe, int i)
{
    u32 val = *(vu32*) probe;
    print_text_fmt_int(140, i, "%x", val);
    return 0 == val || gGlobalTimer == val || gGlobalTimer - 1 == val;
}

static bool doProbeCheck(void* probe, u32 checkValue)
{
    *(vu32*) probe = checkValue;
    return checkValue == *(vu32*) probe;
}

// compiler will attempt to be a funny guy here so need to extern it out
extern void probeStore(void* addr, u32 val);
extern u32 probeLoad(void* addr);
static bool doProbeCheckPJ64(void* probe, u32 checkValue)
{
    probeStore(probe, checkValue);
    return checkValue == probeLoad(probe);
}

static bool probeCheck(void* probe)
{
    if (!doProbeCheck(probe, 0x12345678))
        return false;
    if (!doProbeCheck(probe, 0x87654321))
        return false;
    if (!doProbeCheck(probe, 0xabcdef01))
        return false;

    return true;
}

static void probesReset(void)
{
    if (sProbesOk[0]) *(vu32*) (PROBE0) = gGlobalTimer;
    if (sProbesOk[1]) *(vu32*) (PROBE1) = gGlobalTimer;
    if (sProbesOk[2]) probeStore(PROBE2, gGlobalTimer);
}

static void checkStates()
{
    if (gIsConsole)
    {
        return;
    }

    if (!sProbesChecked)
    {
        sProbesOk[0] = probeCheck((void*) PROBE0);
        sProbesOk[1] = probeCheck((void*) PROBE1);
        if (!sProbesOk[0] && !sProbesOk[1])
        {
            sProbesOk[2] = probeCheck((void*) PROBE2);
        }
        else
        {
            sProbesOk[2] = false;
        }

        probesReset();
        sProbesValid[0] = true;
        sProbesValid[1] = true;
        sProbesValid[2] = true;
        sProbesChecked = true;
    }

    if (1 != gCurrLevelNum)
    {
        print_text_fmt_int(20, 80, "T %d", gGlobalTimer);
        if (sProbesOk[0] && !probeValid(PROBE0, 20)) sProbesValid[0] = false;
        if (sProbesOk[1] && !probeValid(PROBE1, 40)) sProbesValid[1] = false;
        if (sProbesOk[2] && !probeValid(PROBE2, 60)) sProbesValid[2] = false;
    }

    probesReset();

    char statusLine[64];
    sprintf(statusLine, "VALID: %d %d %d", sProbesValid[0], sProbesValid[1], sProbesValid[2]);
    print_text(20, 20, statusLine);

    sprintf(statusLine, "OK: %d %d %d", sProbesOk[0], sProbesOk[1], sProbesOk[2]);
    print_text(20, 40, statusLine);
}

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

extern int sRecCursor;
extern Vec3f sLastFailPosition;
extern u8 gGoMode;

void SaveState_onNormal()
{
    checkStates();

    if (gGoMode)
        return;
    if (gMarioStates->action == ACT_STAR_DANCE_WATER)
        return;

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
        memcpy(Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0) + (_hackticeStateDataEnd1 - _hackticeStateDataStart1), gMarioAnimsMemAlloc, MARIO_ANIMS_POOL_SIZE);
    }
    else
    {
        if (sMustLoadState || (Config_action() == Config_ButtonAction_LOAD_STATE && gSafePosAllowedFrame != gGlobalTimer - 1))
        {
            sMustLoadState = false;
            if (Hacktice_gState->area == gCurrAreaIndex && Hacktice_gState->level == gCurrLevelNum)
            {
                Vec3f pos = { gMarioStates->pos[0], gMarioStates->pos[1], gMarioStates->pos[2]};
                tinymt32_t rng = gGlobalRandomState;
                memcpy(_hackticeStateDataStart0, Hacktice_gState->memory, _hackticeStateDataEnd0 - _hackticeStateDataStart0);
                memcpy(_hackticeStateDataStart1, Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0), _hackticeStateDataEnd1 - _hackticeStateDataStart1);
                memcpy(gMarioAnimsMemAlloc, Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0) + (_hackticeStateDataEnd1 - _hackticeStateDataStart1), MARIO_ANIMS_POOL_SIZE);
                probesReset();

                sLastFailPosition[0] = pos[0];
                sLastFailPosition[1] = pos[1];
                sLastFailPosition[2] = pos[2];
                gIsGravityFlipped = Hacktice_gState->flipped;
                resetCamera();
                gGlobalRandomState = rng;
                (void) random_u16();
#if 0
                sRecCursor = 0;
#endif
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