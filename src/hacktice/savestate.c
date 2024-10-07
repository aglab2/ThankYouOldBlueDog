#include "savestate.h"

#include "binary.h"
#include "cfg.h"
#include "text_manager.h"

#include "game/area.h"
#include "buffers/buffers.h"
#include "game/camera.h"
#include "game/emutest.h"
#include "game/game_init.h"
#include "game/print.h"
#include "game/level_update.h"
#include "game/object_list_processor.h"
#include "game/save_file.h"
#include "engine/math_util.h"
#include "libc/string.h"

// #define DEBUG_EMU

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

u8 gSavedTimer = 0;

static bool sMustSaveState = 0;
static bool sMustLoadState = 0;

extern uint32_t gSafePosAllowedFrame;

extern u32 gIsGravityFlipped;

#define PROBE0 0xb3ff1000
#define PROBE1 0xbffbfff0
#define PROBE2 0x9FFF0004

static bool sProbesChecked = false;
static bool sProbesOk[3];

#ifdef DEBUG_EMU
static char sDebugLine[64] = {};
#endif

static u32 sProbeTime = 0;

// compiler will attempt to be a funny guy here so need to extern it out
extern void probeStore(void* addr, u32 val);
extern u32 probeLoad(void* addr);

static bool probeValueValid(u32 val)
{
    if (val == 0xffffffffU)
    {
        return false;
    }

    return sProbeTime == val || sProbeTime - 1 == val;
}

static bool probeValid(u32 probe, int i)
{
    u32 val = *(vu32*) probe;
    bool valid = probeValueValid(val);
#ifdef DEBUG_EMU
    if (!valid)
    {
        sprintf(sDebugLine, "%x %x", sProbeTime, val);
    }
#endif
    return valid;
}

static bool probeValidPJ64(u32 probe, int i)
{
    u32 val = probeLoad(probe);
    bool valid = probeValueValid(val);
#ifdef DEBUG_EMU
    if (!valid)
    {
        sprintf(sDebugLine, "%x %x", sProbeTime, val);
    }
#endif
    return valid;
}

static bool doProbeCheck(void* probe, u32 checkValue)
{
    *(vu32*) probe = checkValue;
    return checkValue == *(vu32*) probe;
}

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

static bool probeCheckPJ64(void* probe)
{
    if (!doProbeCheckPJ64(probe, 0x12345678))
        return false;
    if (!doProbeCheckPJ64(probe, 0x87654321))
        return false;
    if (!doProbeCheckPJ64(probe, 0xabcdef01))
        return false;

    return true;
}

static bool initSC(void)
{
    probeStore(0x9FFF0000+0x10, 0x00000000);
    probeStore(0x9FFF0000+0x10, 0x5F554E4C);
    probeStore(0x9FFF0000+0x10, 0x4F434B5F);
    return 0x53437632 == probeLoad(0x9FFF0000+0x0C);
}

static void probesReset(void)
{
    if (sProbesOk[0]) *(vu32*) (PROBE0) = sProbeTime;
    if (sProbesOk[1]) *(vu32*) (PROBE1) = sProbeTime;
    if (sProbesOk[2]) probeStore(PROBE2, sProbeTime);
}

static void tamperEmu(void)
{
    sProbeTime = 0xffffffffU;
    save_file_tamper_weak(gCurrSaveFileNum - 1, TAMPER_FLAG_EMU);
}

void SaveState_check()
{
    if (gIsConsole)
    {
        return;
    }

    if (!sProbesChecked)
    {
        sProbesOk[0] = probeCheck((void*) PROBE0);
        if (!sProbesOk[0])
        {
            sProbesOk[1] = probeCheck((void*) PROBE1);
        }
        else
        {
            sProbesOk[1] = false;
        }

        if (!sProbesOk[0] && !sProbesOk[1])
        {
            sProbesOk[2] = initSC() && probeCheckPJ64((void*) PROBE2);
        }
        else
        {
            sProbesOk[2] = false;
        }

        probesReset();
        sProbesChecked = true;
    }

    {
        if (1 != gCurrLevelNum)
        {
            if (0xffffffffU != sProbeTime)
                sProbeTime++;

            if (sProbesOk[0] && !probeValid(PROBE0, 20)) tamperEmu();
            if (sProbesOk[1] && !probeValid(PROBE1, 40)) tamperEmu();
            if (sProbesOk[2] && !probeValidPJ64(PROBE2, 60)) tamperEmu();

            if (!sProbesOk[0] && !sProbesOk[1] && !sProbesOk[2])
            {
                tamperEmu();
            }
        }
        else
        {
            sProbeTime = 0;
        }

        probesReset();
    }

#ifdef DEBUG_EMU
    char statusLine[64];
    sprintf(statusLine, "OK: %d %d %d", sProbesOk[0], sProbesOk[1], sProbesOk[2]);
    print_text(20, 100, statusLine);
#endif
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

extern void bbh_reload_coins();

void SaveState_onNormal()
{
#ifdef DEBUG_EMU
    print_text_fmt_int(20, 20, "%d", gSaveBuffer.files[0][0].tampers);
    print_text_fmt_int(20, 40, "%d", gSaveBuffer.files[1][0].tampers);
    print_text_fmt_int(20, 60, "%d", gSaveBuffer.files[2][0].tampers);
    print_text_fmt_int(20, 80, "%d", gSaveBuffer.files[3][0].tampers);

    print_text(20, 120, sDebugLine);
#endif

    if (gGoMode)
        return;
    if (gMarioStates->action == ACT_STAR_DANCE_WATER)
        return;

    if (sMustSaveState)
    {
        gMarioStates->controller->rawStickX = 0;
        gMarioStates->controller->rawStickY = 0;
        gMarioStates->controller->stickX = 0;
        gMarioStates->controller->stickY = 0;
        gMarioStates->controller->stickMag = 0;
        gMarioStates->controller->buttonDown &= L_TRIG;
        gMarioStates->controller->buttonPressed &= L_TRIG;
        gMarioStates->controller->buttonReleased &= L_TRIG;

        sMustSaveState = false;
        sMustLoadState = false;
        Hacktice_gState->area  = gCurrAreaIndex;
        Hacktice_gState->level = gCurrLevelNum;
        Hacktice_gState->flipped = gIsGravityFlipped;
        Hacktice_gState->size = sizeof(State);
        memcpy(Hacktice_gState->memory, _hackticeStateDataStart0, _hackticeStateDataEnd0 - _hackticeStateDataStart0);
        memcpy(Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0), _hackticeStateDataStart1, _hackticeStateDataEnd1 - _hackticeStateDataStart1);
        memcpy(Hacktice_gState->memory + (_hackticeStateDataEnd0 - _hackticeStateDataStart0) + (_hackticeStateDataEnd1 - _hackticeStateDataStart1), gMarioAnimsMemAlloc, MARIO_ANIMS_POOL_SIZE);
        gSavedTimer = 255;
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
                int starCount = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);
                if (starCount != 13)
                {
                    if (starCount || gMarioStates->pos[0] > -3000.f)
                        save_file_tamper_weak(gCurrSaveFileNum - 1, TAMPER_FLAG_LOAD);
                }
                
                probesReset();
                sLastFailPosition[0] = pos[0];
                sLastFailPosition[1] = pos[1];
                sLastFailPosition[2] = pos[2];
                gIsGravityFlipped = Hacktice_gState->flipped;
                resetCamera();
                gGlobalRandomState = rng;
                (void) random_u16();

                if (gCurrCourseNum == COURSE_BBH)
                    bbh_reload_coins();
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