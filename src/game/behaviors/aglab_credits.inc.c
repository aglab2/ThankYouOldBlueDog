#include "game/ingame_menu.h"

extern u8 gBlackBoxAlpha;
extern u8 gBigBlackBoxAlpha;
extern u8 gSmallBlackBoxAlpha;

extern void load_decompress(const u8* srcStart, const u8* srcEnd, u8* dst);

#define PIC_DECLARE(name) extern u8 _cc_##name##_yay0SegmentRomStart[]; extern u8 _cc_##name##_yay0SegmentRomEnd[];

PIC_DECLARE(pic1)
PIC_DECLARE(pic2)
PIC_DECLARE(pic3)
PIC_DECLARE(pic4)
PIC_DECLARE(pic5)
PIC_DECLARE(pic6)
PIC_DECLARE(pic7)
PIC_DECLARE(pic8)
PIC_DECLARE(pic9)
PIC_DECLARE(pic10)
PIC_DECLARE(pic11)
PIC_DECLARE(pic15)
PIC_DECLARE(pic16)

#undef PIC_DECLARE

extern u8 pic_tr_a_rgba16[];
extern u8 pic_dec_a_rgba16[];

#define oCreditsDecObj oObjF4
#define oCreditsTraOpaObj oObjF8

void bhv_ending_player_init()
{
    set_cam_angle(2); // lakitu cam
    gHudDisplay.flags = HUD_DISPLAY_NONE;
    o->oHealth = 0x880;
}

struct CreditEntry
{
    int lvl;
    const u8* picRomStart;
    const u8* picRomEnd;
    const char* name;
    const char* lines[2];
};

#define PIC(name) _cc_##name##_yay0SegmentRomStart, _cc_##name##_yay0SegmentRomEnd

static const char kWitchOnTheHolyNight[] = "Witch on the Holy Night";
static const char kAiSomniumFiles[] = "AI: The Somnium Files - nirvanA Initiative";
static const char kTheSomnium[] = "The Somnium";

static const struct CreditEntry sCredits[] = {
    { LEVEL_BOB, PIC(pic1) , "Not-as-curly Coaster"  , { kWitchOnTheHolyNight, "Main Theme/Nemuri" }, },
    { LEVEL_WF , PIC(pic2) , "Vanishing Ride"        , { kWitchOnTheHolyNight, "Extra Magic Number?" }, },
    { LEVEL_JRB, PIC(pic3) , "Explosive Ring"        , { "Pomplamoose", "Félicitations!" }, },
    { LEVEL_CCM, PIC(pic4) , "Fearful Flippers"      , { "Super Paper Mario", "Whoa Zone" }, },
    { LEVEL_BBH, PIC(pic5) , "Treacherous Arrows"    , { kWitchOnTheHolyNight, "Imbalance/Blue" } },
    { LEVEL_HMC, PIC(pic6) , "Uppies Glacier"        , { "The Sekimeiya: Spun Glass/Nyah", "Looming" } },
    { LEVEL_LLL, PIC(pic7) , "Fizzle Labyrinth"      , { "Charles Berthoud X Giacomo Turra", "SLAPOCALYPSE" } },
    { LEVEL_SSL, PIC(pic8) , "Cosmic Teamwork"       , { "Castlevania: Legacy of Darkness", "Art Tower" } },
    { LEVEL_DDD, PIC(pic9) , "Quadrivium Adventure"  , { "ROBOTICS;NOTES", "ENERGETIC FORCE" } },
    { LEVEL_SL,  PIC(pic10), "The Vice Paradise"     , { kAiSomniumFiles, "Quiz Nervine" } },
    { LEVEL_WDW, PIC(pic11), "Midwinter Clickin'"    , { kWitchOnTheHolyNight, "Working!!" } },

    { LEVEL_RR,  PIC(pic15), kTheSomnium             , { kAiSomniumFiles, "Novel Ingress" } },
    { LEVEL_SA,  PIC(pic16),kTheSomnium              , { "World's End Girlfriend", "Scorpius Circus" } },
};

#undef PIC

static void renderTopText(u8 a)
{
    gDeferredFancyText[0].x = 160;
    gDeferredFancyText[0].y = 200;
    gDeferredFancyText[0].aligned = 1;
    gDeferredFancyText[0].alpha = a;
    gDeferredFancyText[0].line = "Thank You Old Blue Dog";
}

static void renderInitText(u8 a)
{
    gDeferredFancyText[1].x = 160;
    gDeferredFancyText[1].y = 120;
    gDeferredFancyText[1].aligned = 1;
    gDeferredFancyText[1].alpha = a;
    gDeferredFancyText[1].line = "Made by aglab2";
}

static void renderToolsText(u8 a)
{
    gDeferredFancyText[2].x = 70;
    gDeferredFancyText[2].y = 95;
    gDeferredFancyText[2].aligned = 0;
    gDeferredFancyText[2].alpha = a;
    gDeferredFancyText[2].line = "Tools used:\nHackerSM64\nBlender+Fast64\nSTRM64";
}

static void renderTestersText(u8 a)
{
    gDeferredFancyText[3].x = 180;
    gDeferredFancyText[3].y = 95;
    gDeferredFancyText[3].aligned = 0;
    gDeferredFancyText[3].alpha = a;
    gDeferredFancyText[3].line = "Testers:\namsixx\nMushie64";
}

static void renderSpecialThanksText(u8 a)
{
    gDeferredFancyText[4].x = 160;
    gDeferredFancyText[4].y = 115;
    gDeferredFancyText[4].aligned = 1;
    gDeferredFancyText[4].alpha = a;
    gDeferredFancyText[4].line = "Special Thanks";

    gDeferredFancyText[5].x = 160;
    gDeferredFancyText[5].y = 85;
    gDeferredFancyText[5].aligned = 1;
    gDeferredFancyText[5].alpha = a;
    gDeferredFancyText[5].line = "SezNative Reminiscence Team\nMorningStorm64 & katze789\nIWBTG Fangame Community";
}

void bhv_ending_player_loop()
{
#if 1
    struct MarioStates* m = gMarioStates;
    set_mario_action(m, 0, 0);
    gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[0];
    gPlayer1Controller->buttonDown = 0;
    gPlayer1Controller->buttonPressed = 0;
    gPlayer1Controller->stickX = 0;
    gPlayer1Controller->stickY = 0;
    gPlayer1Controller->rawStickX = 0;
    gPlayer1Controller->rawStickY = 0;
    auto camera = gCurrentArea->camera;
    set_camera_mode_8_directions(camera);
    reset_camera(camera);
#endif

    if (0 == o->oTimer)
    {
        o->oCreditsTraOpaObj = spawn_object(o, MODEL_SA_TRA_OPA, bhvStaticObject);
        o->oCreditsTraOpaObj->oPosZ += 200.f;
        o->oCreditsTraOpaObj->oPosX -= 220.f;
        obj_scale(o->oCreditsTraOpaObj, 0.54f);
        o->oCreditsTraOpaObj->oOpacity = 0;

        o->oCreditsDecObj = spawn_object(o, MODEL_SA_DECAL, bhvStaticObject);
        o->oCreditsDecObj->oPosZ += 200.f;
        o->oCreditsDecObj->oPosX -= 220.f;
        obj_scale(o->oCreditsDecObj, 0.54f);
        o->oCreditsDecObj->oOpacity = 0;
    }

    const int kInitialWait = 150;
    int timeline = o->oTimer;
    if (timeline < kInitialWait)
        return;
    timeline -= kInitialWait;

    const int kFadeInBlackBox = 64;
    if (timeline < kFadeInBlackBox)
    {
        gBigBlackBoxAlpha = gBlackBoxAlpha = timeline * 200 / kFadeInBlackBox;
        renderTopText(timeline * 255 / kFadeInBlackBox);
        renderInitText(timeline * 255 / kFadeInBlackBox);
        return;
    }
    timeline -= kFadeInBlackBox;
    
    const int kPostFadeInWait = 20;
    if (timeline < kPostFadeInWait)
    {
        renderTopText(255);
        renderInitText(255);
        return;
    }
    timeline -= kPostFadeInWait;

    if (timeline < kFadeInBlackBox)
    {
        renderTopText(255);
        renderInitText(255);
        renderToolsText(timeline * 255 / kFadeInBlackBox);
        return;
    }
    timeline -= kFadeInBlackBox;

    if (timeline < kPostFadeInWait)
    {
        renderTopText(255);
        renderInitText(255);
        renderToolsText(255);
        return;
    }
    timeline -= kPostFadeInWait;

    if (timeline < kFadeInBlackBox)
    {
        renderTopText(255);
        renderInitText(255);
        renderToolsText(255);
        renderTestersText(timeline * 255 / kFadeInBlackBox);
        return;
    }
    timeline -= kFadeInBlackBox;

    const int kPostFadeInPreFadeoutWait = 40;
    if (timeline < kPostFadeInPreFadeoutWait)
    {
        renderTopText(255);
        renderInitText(255);
        renderToolsText(255);
        renderTestersText(255);
        return;
    }
    timeline -= kPostFadeInPreFadeoutWait;

    const int kFadeout = 64;
    if (timeline < kFadeout)
    {
        renderTopText(255);
        renderInitText((kFadeout - timeline) * 255 / kFadeout);
        renderToolsText((kFadeout - timeline) * 255 / kFadeout);
        renderTestersText((kFadeout - timeline) * 255 / kFadeout);
        return;
    }
    timeline -= kFadeout;

    if (timeline < kFadeInBlackBox)
    {
        renderTopText(255);
        renderSpecialThanksText(timeline * 255 / kFadeInBlackBox);
        return;
    }

    const int kPreFullFadeout = 180;
    if (timeline < kPreFullFadeout)
    {
        renderTopText(255);
        renderSpecialThanksText(255);
        return;
    }
    timeline -= kPreFullFadeout;

    if (timeline < kFadeout)
    {
        gBigBlackBoxAlpha = (kFadeout - timeline) * 200 / kFadeout;
        renderTopText((kFadeout - timeline) * 255 / kFadeout);
        renderSpecialThanksText((kFadeout - timeline) * 255 / kFadeout);
        return;
    }
    timeline -= kFadeout;

    const int kFadeInCredits = 64;
    if (timeline < kFadeInCredits)
    {
        gBigBlackBoxAlpha = 0;
        gSmallBlackBoxAlpha = timeline * 200 / kFadeInCredits;
        o->oCreditsTraOpaObj->oOpacity = timeline * 255 / kFadeInCredits;
        return;
    }
}
