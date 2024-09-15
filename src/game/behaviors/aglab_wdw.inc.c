extern const Collision wdw_0_collision[];
extern const Collision wdw_1_collision[];

#define oWdwCtlWasOnPlatformBefore oF4
#define oWdwCtlPrevAction oFC

void bhv_wdw_ctl_init()
{
    cur_obj_set_model(MODEL_WDW_0);
    obj_set_collision_data(o, wdw_0_collision);
    o->oWdwCtlWasOnPlatformBefore = 0;
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
}
