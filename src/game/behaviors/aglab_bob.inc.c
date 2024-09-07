
#define oBobCtrlCurr oObjF4
#define oBobCtrlNext oObjF8

extern const BehaviorScript bhvBobInit[];
extern const BehaviorScript bhvBobMove[];

void bhv_bob_ctrl_init()
{
    o->oBobCtrlCurr = spawn_object(o, MODEL_BOB_INIT, bhvBobInit);
    o->oBobCtrlCurr->oOpacity = 255;
    o->oBobCtrlNext = NULL;
}

static const s16 kAngles[] = { -0x800, -0x700, -0x600, 0x600, 0x700, 0x800 };

void bhv_bob_ctrl_loop()
{
    switch (o->oAction)
    {
        case 0:
        {
            if (gMarioObject->platform == o->oBobCtrlCurr)
            {
                o->oPosY -= 300.f;
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
