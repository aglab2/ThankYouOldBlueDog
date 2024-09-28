extern const Collision wdw_0_collision[];
extern const Collision wdw_1_collision[];

#define oWdwCtlWasOnPlatformBefore oF4
#define oWdwCtlPrevAction oFC
#define oWdwCtlTrajProgress oF8
#define oWdwDeathTime o100

extern const Trajectory wdw_area_2_spline_star_curve[];

void bhv_wdw_ctl_init()
{
    cur_obj_set_model(MODEL_WDW_0);
    obj_set_collision_data(o, wdw_0_collision);
    o->oWdwCtlWasOnPlatformBefore = 0;
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    
    if (is_hm())
    {
        o->oWdwCtlTrajProgress = 0;
        o->oWdwDeathTime = 30;
        const Trajectory* traj = segmented_to_virtual(wdw_area_2_spline_star_curve);
        o->parentObj->oPosX = traj[1];
        o->parentObj->oPosY = traj[2];
        o->parentObj->oPosZ = traj[3];
        o->parentObj->oIntangibleTimer = -1;
    }
}

static void wdw_switch()
{
    o->oAction = !o->oAction;
    if (o->oAction)
    {
        cur_obj_set_model(MODEL_WDW_1);
        obj_set_collision_data(o, wdw_1_collision);
    }
    else
    {
        cur_obj_set_model(MODEL_WDW_0);
        obj_set_collision_data(o, wdw_0_collision);
    }
}

void bhv_wdw_ctl_loop()
{
    int onPlatform = gMarioObject->platform == o;
    if (o->oWdwCtlWasOnPlatformBefore && !onPlatform)
    {
        wdw_switch();
    }
    o->oWdwCtlWasOnPlatformBefore = onPlatform;

    if (o->oWdwCtlPrevAction != gMarioStates->action && gMarioStates->action == ACT_WALL_KICK_AIR)
    {
        wdw_switch();
    }
    o->oWdwCtlPrevAction = gMarioStates->action;

    if (is_hm())
    {
        static char line[10];
        gDeferredFancyText[0].x = 20;
        gDeferredFancyText[0].y = 20;
        gDeferredFancyText[0].aligned = 0;
        gDeferredFancyText[0].alpha = 255;
        gDeferredFancyText[0].line = line;
        sprintf(line, "%d.%02d", o->oWdwDeathTime / 30, 3 * (o->oWdwDeathTime % 30));
        if (gMarioStates->floor && gMarioStates->floor->type == SURFACE_NOISE_DEFAULT)
            return;

        o->parentObj->oIntangibleTimer = -1;

        f32 dx = o->parentObj->oPosX - gMarioStates->pos[0];
        f32 dy = o->parentObj->oPosY - (gMarioStates->pos[1] + 80.f);
        f32 dz = o->parentObj->oPosZ - gMarioStates->pos[2];
        f32 d = dx * dx + dy * dy + dz * dz;
        if (d < 23000.f)
        {
            const Trajectory* traj = segmented_to_virtual(wdw_area_2_spline_star_curve);
            o->oWdwCtlTrajProgress++;
            if (-1 == traj[4 * o->oWdwCtlTrajProgress])
            {
                o->parentObj->oIntangibleTimer = 0;
                o->activeFlags = 0;
                return;
            }
            o->parentObj->oPosX = traj[o->oWdwCtlTrajProgress * 4 + 1];
            o->parentObj->oPosY = traj[o->oWdwCtlTrajProgress * 4 + 2];
            o->parentObj->oPosZ = traj[o->oWdwCtlTrajProgress * 4 + 3];
            o->oWdwDeathTime += 30;
            play_sound(SOUND_GENERAL_COIN_SPURT, gMarioStates->marioObj->header.gfx.cameraToObject);
        }

        if (o->oWdwDeathTime)
        {
            o->oWdwDeathTime--;
            if (0 == o->oWdwDeathTime)
            {
                gMarioStates->action = 0;
            }
        }
    }
}
