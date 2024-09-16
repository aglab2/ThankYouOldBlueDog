void bhv_ddd_move_init()
{
    o->oMoveAngleYaw = 0x4000;
}

static int obj_count_opened_gate_switches()
{
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvFloorSwitchGrills);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;
    int amount = 0;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
            && obj->oAction == OPENABLE_GRILL_DOOR_ACT_OPEN
        ) {
            amount++;
        }

        obj = (struct Object *) obj->header.next;
    }

    return amount;
}

void bhv_ddd_move_loop()
{
    o->oCollisionDistance = 10000.f;
    if (0 == o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            o->oAction = 1;
            o->oForwardVel = 35.0f;
        }
    }
    else
    {
        o->oMoveAngleYaw = 0x4000 * (1 - obj_count_opened_gate_switches());
    }

    cur_obj_move_using_fvel_and_gravity();
}
