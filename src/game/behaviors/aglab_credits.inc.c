#include "game/ingame_menu.h"
#include "game/emutest.h"

#define oCreditsDecObj oObjF4
#define oCreditsTraOpaObj oObjF8
#define oCreditsProgress oFC
// corresponds to o100
#define oCreditsCurrEntry OBJECT_FIELD_VPTR(0x1E)
// corresponds to o104
#define oCreditsPrevEntry OBJECT_FIELD_VPTR(0x1F)

extern u8 gBlackBoxAlpha;
extern u8 gBigBlackBoxAlpha;
extern u8 gSmallBlackBoxAlpha;
extern u8 gBottomBlackBoxAlpha;
extern uint8_t kLevelsOrder[];
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

extern u8 pic_tr__0_rgba16[];
extern u8 pic_dec_a_rgba16[];

void bhv_ending_player_init()
{
    set_cam_angle(2); // lakitu cam
    gHudDisplay.flags = HUD_DISPLAY_NONE;
    o->oHealth = 0x880;
    
    o->oCreditsTraOpaObj = spawn_object(o, MODEL_SA_TRA_OPA, bhvStaticObject);
    o->oCreditsTraOpaObj->oPosZ += 200.f;
    o->oCreditsTraOpaObj->oPosY += 30.f;
    o->oCreditsTraOpaObj->oPosX -= 220.f;
    obj_scale(o->oCreditsTraOpaObj, 0.54f);
    o->oCreditsTraOpaObj->oOpacity = 0;

    o->oCreditsDecObj = spawn_object(o, MODEL_SA_DECAL, bhvStaticObject);
    o->oCreditsDecObj->oPosZ += 200.f;
    o->oCreditsDecObj->oPosY += 30.f;
    o->oCreditsDecObj->oPosX -= 220.f;
    obj_scale(o->oCreditsDecObj, 0.54f);
    o->oCreditsDecObj->oOpacity = 0;
}

struct CreditEntry
{
    u8 lvl;
    u8 shift;
    const u8* picRomStart;
    const u8* picRomEnd;
    const char* name;
    const char* lines[3];
};

#define PIC(name) _cc_##name##_yay0SegmentRomStart, _cc_##name##_yay0SegmentRomEnd

static const char kWitchOnTheHolyNight[] = "Witch on the Holy Night";
static const char kAiSomniumFiles[] = "AI: The Somnium Files";
static const char kTheSomnium[] = "The Somnium";

static const struct CreditEntry sFirstCreditEntry = { 0, 0, PIC(pic1), "Skill Check Observatory", { kWitchOnTheHolyNight, "Innocence" } };
static const struct CreditEntry sCredits[] = {
    { LEVEL_BOB, 0, PIC(pic1) , "Not-as-curly Coaster"  , { kWitchOnTheHolyNight, "Main Theme/Nemuri" }, },
    { LEVEL_WF , 0, PIC(pic2) , "Vanishing Ride"        , { kWitchOnTheHolyNight, "Extra Magic Number?" }, },
    { LEVEL_JRB, 0, PIC(pic3) , "Explosive Ring"        , { "Pomplamoose", "Felicitations!" }, },
    { LEVEL_CCM, 0, PIC(pic4) , "Fearful Flippers"      , { "Super Paper Mario", "Whoa Zone" }, },
    { LEVEL_BBH, 0, PIC(pic5) , "Treacherous Arrows"    , { kWitchOnTheHolyNight, "Imbalance/Blue" } },
    { LEVEL_HMC, 9, PIC(pic6) , "Uppies Glacier"        , { "The Sekimeiya: Spun Glass", "Nyah\nLooming" } },
    { LEVEL_LLL, 9, PIC(pic7) , "Fizzle Labyrinth"      , { "Charles Berthoud", "Giacomo Turra\nSLAPOCALYPSE" } },
    { LEVEL_SSL, 9, PIC(pic8) , "Cosmic Teamwork"       , { "Castlevania", "Legacy of Darkness\nArt Tower" } },
    { LEVEL_DDD, 0, PIC(pic9) , "Quadrivium Adventure"  , { "ROBOTICS NOTES", "ENERGETIC FORCE" } },
    { LEVEL_SL,  9, PIC(pic10), "The Vice Paradise"     , { kAiSomniumFiles, "nirvanA Initiative\nQuiz Nervine" } },
    { LEVEL_WDW, 0, PIC(pic11), "Midwinter Clickin'"    , { kWitchOnTheHolyNight, "Working!!" } },

    { LEVEL_RR,  9, PIC(pic15), kTheSomnium             , { kAiSomniumFiles, "nirvanA Initiative\nNovel Ingress" } },
    { LEVEL_SA,  9, PIC(pic16), kTheSomnium             , { "World's End Girlfriend", "Scorpius Circus" } },
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
    gDeferredFancyText[1].y = 120 + 5;
    gDeferredFancyText[1].aligned = 1;
    gDeferredFancyText[1].alpha = a;
    gDeferredFancyText[1].line = "Made by aglab2";
}

static void renderToolsText(u8 a)
{
    gDeferredFancyText[2].x = 70;
    gDeferredFancyText[2].y = 95 + 5;
    gDeferredFancyText[2].aligned = 0;
    gDeferredFancyText[2].alpha = a;
    gDeferredFancyText[2].line = "Tools used:\nHackerSM64\nBlender+Fast64\nSTRM64";
}

static void renderTestersText(u8 a)
{
    gDeferredFancyText[3].x = 180;
    gDeferredFancyText[3].y = 95 + 5;
    gDeferredFancyText[3].aligned = 0;
    gDeferredFancyText[3].alpha = a;
    gDeferredFancyText[3].line = "Testers:\namsixx\nMushie64";
}

static void renderSpecialThanksText(u8 a)
{
    gDeferredFancyText[4].x = 160;
    gDeferredFancyText[4].y = 115 + 5;
    gDeferredFancyText[4].aligned = 1;
    gDeferredFancyText[4].alpha = a;
    gDeferredFancyText[4].line = "Special Thanks";

    gDeferredFancyText[5].x = 160;
    gDeferredFancyText[5].y = 85 + 5;
    gDeferredFancyText[5].aligned = 1;
    gDeferredFancyText[5].alpha = a;
    gDeferredFancyText[5].line = "SezNative Reminiscence Team\nMorningStorm64 & katze789\nIWBTG Fangame Community";
}

static void renderCreditEntry(const struct CreditEntry* entry, u8 a, int off)
{
    gDeferredFancyText[off + 1].x = 170;
    gDeferredFancyText[off + 1].y = 115 + entry->shift;
    gDeferredFancyText[off + 1].aligned = 0;
    gDeferredFancyText[off + 1].alpha = a;
    gDeferredFancyText[off + 1].line = entry->name;

    gDeferredFancyText[off + 2].x = 170;
    gDeferredFancyText[off + 2].y = 76 + entry->shift;
    gDeferredFancyText[off + 2].aligned = 0;
    gDeferredFancyText[off + 2].alpha = a;
    gDeferredFancyText[off + 2].line = entry->lines[0];

    gDeferredFancyText[off + 3].x = 170;
    gDeferredFancyText[off + 3].y = 60 + entry->shift;
    gDeferredFancyText[off + 3].aligned = 0;
    gDeferredFancyText[off + 3].alpha = a;
    gDeferredFancyText[off + 3].line = entry->lines[1];
}

static void credits_initial_wait()
{
    const int kInitialWait = 150;
    if (o->oTimer == kInitialWait)
        o->oAction++;
}

const int kFadeInBlackBox = 64;
const int kPostFadeInWait = 20;
static void credits_show_creator()
{
    gBlackBoxAlpha = gBigBlackBoxAlpha = CLAMP(o->oTimer * 200 / kFadeInBlackBox, 0, 200);
    u8 textAlpha = CLAMP(o->oTimer * 255 / kFadeInBlackBox, 0, 255);
    renderTopText(textAlpha);
    renderInitText(textAlpha);
    if (o->oTimer == kFadeInBlackBox + kPostFadeInWait)
        o->oAction++;
}

static void credits_show_tools()
{
    renderTopText(255);
    renderInitText(255);
    renderToolsText(CLAMP(o->oTimer * 255 / kFadeInBlackBox, 0, 255));
    if (o->oTimer == kFadeInBlackBox + kPostFadeInWait)
        o->oAction++;
}

static void credits_show_testers()
{
    renderTopText(255);
    renderInitText(255);
    renderToolsText(255);
    renderTestersText(CLAMP(o->oTimer * 255 / kFadeInBlackBox, 0, 255));
    if (o->oTimer == kFadeInBlackBox + kPostFadeInWait)
        o->oAction++;
}

const int kFadeout = 64;
static void credits_fade_first()
{
    renderTopText(255);
    renderInitText((kFadeout - o->oTimer) * 255 / kFadeout);
    renderToolsText((kFadeout - o->oTimer) * 255 / kFadeout);
    renderTestersText((kFadeout - o->oTimer) * 255 / kFadeout);
    if (o->oTimer == kFadeout)
        o->oAction++;
}

static void credits_show_special_thanks()
{
    renderTopText(255);
    const int kPreFullFadeout = 140;
    renderSpecialThanksText(CLAMP(o->oTimer * 255 / kFadeInBlackBox, 0, 255));
    if (o->oTimer == kFadeInBlackBox + kPreFullFadeout)
        o->oAction++;
}

static void credits_fade_special_thanks()
{
    renderTopText(255);
    gBigBlackBoxAlpha = (kFadeout - o->oTimer) * 200 / kFadeout;
    renderSpecialThanksText((kFadeout - o->oTimer) * 255 / kFadeout);
    if (o->oTimer == kFadeout)
        o->oAction++;
}

const int kFadeInCredits = 64;
#define kCreditsEntryWait (gIsConsole ? 120 : 200)
static void credits_show_first_entry()
{
    renderTopText(255);
    gSmallBlackBoxAlpha = CLAMP(o->oTimer * 200 / kFadeInCredits, 0, 200);
    u8 textAlpha = CLAMP(o->oTimer * 255 / kFadeInCredits, 0, 255);
    o->oCreditsTraOpaObj->oOpacity = textAlpha;
    o->oCreditsCurrEntry = &sFirstCreditEntry;
    renderCreditEntry(&sFirstCreditEntry, textAlpha, 0);
    if (o->oTimer == kFadeInCredits + kCreditsEntryWait)
        o->oAction++;
}

static void credits_switch_entry()
{
    renderTopText(255);
    const int kCreditsEntrySwitch = 64;
    if (0 == o->oTimer)
    {
        o->oCreditsPrevEntry = o->oCreditsCurrEntry;
        int level = kLevelsOrder[o->oCreditsProgress];
        o->oCreditsCurrEntry = NULL;
        for (int i = 0; i < sizeof(sCredits) / sizeof(sCredits[0]); i++)
        {
            if (sCredits[i].lvl == level)
            {
                o->oCreditsCurrEntry = &sCredits[i];
                break;
            }
        }

        const struct CreditEntry* entry = (const struct CreditEntry*) o->oCreditsCurrEntry;
        load_decompress(entry->picRomStart, entry->picRomEnd, segmented_to_virtual(pic_dec_a_rgba16));
    }

    o->oCreditsDecObj->oOpacity = o->oTimer * 255 / kCreditsEntrySwitch;
    renderCreditEntry((const struct CreditEntry*) o->oCreditsPrevEntry, (kCreditsEntrySwitch - o->oTimer) * 255 / kCreditsEntrySwitch, 0);
    renderCreditEntry((const struct CreditEntry*) o->oCreditsCurrEntry, o->oTimer * 255 / kCreditsEntrySwitch, 3);

    if (o->oTimer == kCreditsEntrySwitch)
    {
        // this will cause race condition with RDP but it is not a big deal (I hope)
        memcpy(segmented_to_virtual(pic_tr__0_rgba16), segmented_to_virtual(pic_dec_a_rgba16), 345632 - 8*4);
        o->oCreditsDecObj->oOpacity = 0;
        o->oAction++;
    }
}

static void credits_entry_render()
{
    renderTopText(255);
    renderCreditEntry((const struct CreditEntry*) o->oCreditsCurrEntry, 255, 0);
    if (o->oTimer == kCreditsEntryWait)
    {
        o->oCreditsProgress++;
        if (13 == o->oCreditsProgress)
            o->oAction++;
        else
            o->oAction--;
    }
}

static void credits_hide()
{
    int textFadeSpeed = (kFadeout - o->oTimer) * 255 / kFadeout;
    int alphaBoxFadeSpeed = (kFadeout - o->oTimer) * 200 / kFadeout;
    renderTopText(textFadeSpeed);
    gSmallBlackBoxAlpha = alphaBoxFadeSpeed;
    gBlackBoxAlpha = alphaBoxFadeSpeed;
    renderCreditEntry((const struct CreditEntry*) o->oCreditsCurrEntry, textFadeSpeed, 0);
    o->oCreditsTraOpaObj->oOpacity = textFadeSpeed;
    if (o->oTimer == kFadeout)
        o->oAction++;
}

static void credits_thanks()
{
    gDeferredFancyText[0].x = 160;
    gDeferredFancyText[0].y = 200;
    gDeferredFancyText[0].aligned = 1;
    gDeferredFancyText[0].alpha = CLAMP(-20 + o->oTimer * 3, 0, 255);
    gDeferredFancyText[0].line = "Thank You!";

    static const char kEntry[] = "Credits Theme:\nThe House in Fata Morgana - A Requiem for Innocence\nSerie de Fragmento (instrumental)";
    if (o->oTimer > 900)
    {
        gDeferredFancyText[1].x = 25;
        gDeferredFancyText[1].y = 40;
        gDeferredFancyText[1].aligned = 0;
        gDeferredFancyText[1].alpha = CLAMP(255 - (o->oTimer - 900) * 3, 0, 255);
        gDeferredFancyText[1].line = kEntry;
        gBottomBlackBoxAlpha = CLAMP(gDeferredFancyText[1].alpha, 0, 200);
    }
    else if (o->oTimer > 300)
    {
        gDeferredFancyText[1].x = 25;
        gDeferredFancyText[1].y = 40;
        gDeferredFancyText[1].aligned = 0;
        gDeferredFancyText[1].alpha = CLAMP((o->oTimer - 300) * 3, 0, 255);
        gDeferredFancyText[1].line = kEntry;
        gBottomBlackBoxAlpha = CLAMP(gDeferredFancyText[1].alpha, 0, 200);
    }
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

    switch (o->oAction)
    {
    case 0:
        credits_initial_wait();
        break;
    case 1:
        credits_show_creator();
        break;
    case 2:
        credits_show_tools();
        break;
    case 3:
        credits_show_testers();
        break;
    case 4:
        credits_fade_first();
        break;
    case 5:
        credits_show_special_thanks();
        break;
    case 6:
        credits_fade_special_thanks();
        break;
    case 7:
        credits_show_first_entry();
        break;
    case 8:
        credits_switch_entry();
        break;
    case 9:
        credits_entry_render();
        break;
    case 10:
        credits_hide();
        break;
    case 11:
        credits_thanks();
        break;
    }
}
