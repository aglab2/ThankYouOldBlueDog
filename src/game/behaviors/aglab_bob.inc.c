
#define oBobCtrlCurr oObjF4
#define oBobCtrlNext oObjF8
#define oBobCtrlStar oObjFC

extern const BehaviorScript bhvBobInit[];
extern const BehaviorScript bhvBobMove[];

void bhv_bob_ctrl_init()
{
    o->oBobCtrlCurr = spawn_object(o, MODEL_BOB_INIT, bhvBobInit);
    o->oBobCtrlCurr->oOpacity = 255;
    o->oBobCtrlNext = NULL;
    o->oBobCtrlStar = cur_obj_nearest_object_with_behavior(bhvStar);
    o->oBobCtrlStar->oPosY -= 5500.f;
}

static const s16 kAngles[] = { -0x800, -0x700, -0x600, 0x600, 0x700, 0x800 };

extern const Collision bob_move_collision[];
void bhv_bob_ctrl_loop()
{
    switch (o->oAction)
    {
        case 0:
        {
            if (gMarioObject->platform == o->oBobCtrlCurr)
            {
                if (o->oBobCtrlCurr->behavior == bhvBobInit)
                {
                    f32 d = gMarioStates->pos[0] * gMarioStates->pos[0] + gMarioStates->pos[2] * gMarioStates->pos[2];
                    if (d > 20000.f)
                    {
                        return;
                    }
                    else
                    {
                        obj_set_model(o->oBobCtrlCurr, MODEL_BOB_MOVE);
                        obj_set_collision_data(o->oBobCtrlCurr, bob_move_collision);
                    }
                }

                o->oPosY -= 300.f;
                o->oBobCtrlStar->oPosY += 30.f;
                o->oBobCtrlNext = spawn_object(o, MODEL_BOB_MOVE, bhvBobMove);
                o->oBobCtrlNext->oOpacity = 255;
                o->oBobCtrlNext->oFaceAngleYaw   = random_u16();
                o->oBobCtrlNext->oFaceAnglePitch = kAngles[random_u16() % (sizeof(kAngles) / sizeof(kAngles[0]))];
                o->oBobCtrlNext->oFaceAngleRoll  = kAngles[random_u16() % (sizeof(kAngles) / sizeof(kAngles[0]))];
                o->oAction = 1;
            }
            break;
        }
        case 1:
        {
            o->oBobCtrlCurr->oOpacity -= 5;
            if (o->oBobCtrlCurr->oOpacity == 0)
            {
                o->oBobCtrlCurr->activeFlags = 0;
                o->oBobCtrlCurr = o->oBobCtrlNext;
                o->oBobCtrlNext = NULL;
                o->oAction = 0;
            }
            break;
        }
    }
}
