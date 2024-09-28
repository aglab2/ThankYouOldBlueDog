#define oWfTrajProgress oFloatF8
#define oWfTrajCurPoint oFC
#define oWfMoveTrajIdx o100

// Moving 30 platform in a loop

extern const Trajectory wf_area_1_spline_traj0[];
extern const Trajectory wf_area_1_spline_traj1[];

static void wf_traj_instantiate(const Trajectory* kTraj, int id)
{
    const int amount = 30;
    f32 trajLength = 0.f;
    const Trajectory* traj = kTraj;
    while (traj[0] != -1)
    {
        Vec3f currPoint = { traj[1], traj[2], traj[3] };
        Vec3f nextPoint = { traj[5], traj[6], traj[7] };
        if (traj[4] == -1)
        {
            nextPoint[0] = kTraj[1];
            nextPoint[1] = kTraj[2];
            nextPoint[2] = kTraj[3];
        }

        f32 dx = nextPoint[0] - currPoint[0];
        f32 dy = nextPoint[1] - currPoint[1];
        f32 dz = nextPoint[2] - currPoint[2];
        trajLength += sqrtf(dx * dx + dy * dy + dz * dz);

        traj += 4;
    }

    o->oWfTrajProgress = 0.f;
    o->oWfTrajCurPoint = 0;
    f32 vel = trajLength / amount;

    {
        struct Object* mov;
        mov = spawn_object(o, MODEL_WF_MOVE_SAFE, bhvWfMoveSafe);
        mov->oOpacity = 0;
        mov->oPosX = kTraj[1];
        mov->oPosY = kTraj[2];
        mov->oPosZ = kTraj[3];
        mov->oWfTrajProgress = o->oWfTrajProgress;
        mov->oWfTrajCurPoint = o->oWfTrajCurPoint;
        // mov->oForwardVel = 16.f;
        mov->oWfMoveTrajIdx = id;
    }

    for (int i = 0; i < amount - 1; i++)
    {
        traj = &kTraj[4 * o->oWfTrajCurPoint];
        Vec3f trajCurrPoint = { traj[1], traj[2], traj[3] };
        Vec3f trajNextPoint = { traj[5], traj[6], traj[7] };
        if (traj[4] == -1)
        {
            trajNextPoint[0] = kTraj[1];
            trajNextPoint[1] = kTraj[2];
            trajNextPoint[2] = kTraj[3];
        }

        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);
        f32 dirMag = vec3_mag(trajDirection);
        
        f32 movAmt = vel / dirMag;
        f32 preProgress = o->oWfTrajProgress;
        o->oWfTrajProgress += movAmt;
        if (o->oWfTrajProgress >= 1.f)
        {
            f32 consumedProgress = 1.f - preProgress;
            f32 consumedMag = consumedProgress * dirMag;
            f32 remainingVel = vel - consumedMag;
            
            o->oWfTrajCurPoint++;
            {
                // now calculate the velocity for the next point using the same principle
                // this assume vel isn't too big to skip multiple points
                traj = &kTraj[4 * o->oWfTrajCurPoint];
                Vec3f trajCurrPoint = { traj[1], traj[2], traj[3] };
                Vec3f trajNextPoint = { traj[5], traj[6], traj[7] };
                if (traj[4] == -1)
                {
                    trajNextPoint[0] = kTraj[1];
                    trajNextPoint[1] = kTraj[2];
                    trajNextPoint[2] = kTraj[3];
                }

                Vec3f trajDirection;
                vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);
                f32 dirMag2 = vec3_mag(trajDirection);

                o->oWfTrajProgress = remainingVel / dirMag2;
            }
        }
        
        {
            traj = &kTraj[4 * o->oWfTrajCurPoint];
            Vec3f trajCurrPoint = { traj[1], traj[2], traj[3] };
            Vec3f trajNextPoint = { traj[5], traj[6], traj[7] };
            if (-1 == traj[4])
            {
                trajNextPoint[0] = kTraj[1];
                trajNextPoint[1] = kTraj[2];
                trajNextPoint[2] = kTraj[3];
            }

            Vec3f trajDirection;
            vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);

            struct Object* mov;
            if ((i % 3) == 0)
            {
                mov = spawn_object(o, MODEL_WF_MOVE_SAFE, bhvWfMoveSafe);
                mov->oOpacity = 255;
            }
            else
            {
                mov = spawn_object(o, MODEL_WF_MOVE_SAFE, bhvWfMoveSafe);
                mov->oOpacity = 0;
            }

            mov->oPosX = trajCurrPoint[0] + (trajDirection[0] * o->oWfTrajProgress);
            mov->oPosY = trajCurrPoint[1] + (trajDirection[1] * o->oWfTrajProgress);
            mov->oPosZ = trajCurrPoint[2] + (trajDirection[2] * o->oWfTrajProgress);
            mov->oWfTrajProgress = o->oWfTrajProgress;
            mov->oWfTrajCurPoint = o->oWfTrajCurPoint;
            // mov->oForwardVel = 16.f;
            mov->oWfMoveTrajIdx = id;
        }
    }
}

void bhv_wf_ctrl_init()
{
    wf_traj_instantiate(segmented_to_virtual(wf_area_1_spline_traj0), 0);
    wf_traj_instantiate(segmented_to_virtual(wf_area_1_spline_traj1), 1);
}

void bhv_wf_ctrl_loop()
{
}

void bhv_wf_move_init()
{
    obj_scale(o, 0.33f);
    o->oDrawingDistance = 10000.f;
}

extern const Collision wf_movedeath_collision[];
extern const Collision wf_movesafe_collision[];
void bhv_wf_move_loop()
{
    if (o->oOpacity < 10)
    {
        obj_set_collision_data(o, wf_movedeath_collision);
    }
    else
    {
        obj_set_collision_data(o, wf_movesafe_collision);
    }

    if (0 == o->oAction)
    {
        if (255 == o->oOpacity && gMarioObject->platform == o)
        {
            o->oAction = 1;
            cur_obj_play_sound_2(SOUND_GENERAL_MOVING_IN_SAND);
        }
    }
    else if (1 == o->oAction)
    {
        if (o->oOpacity > 7)
        {
            o->oOpacity -= 7;
        }
        else
        {
            o->oOpacity = 0;
            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
        if (o->oTimer > 45)
        {
            int amt = o->oOpacity + 50;
            o->oOpacity = CLAMP(amt, 0, 255);
            if (o->oOpacity == 255)
            {
                o->oAction = 0;
            }
        }
    }

    const Trajectory* kTraj = segmented_to_virtual(o->oWfMoveTrajIdx ? wf_area_1_spline_traj1 : wf_area_1_spline_traj0);
    const Trajectory* traj = &kTraj[4 * o->oWfTrajCurPoint];
    Vec3f trajCurrPoint = { traj[1], traj[2], traj[3] };
    Vec3f trajNextPoint = { traj[5], traj[6], traj[7] };
    if (traj[4] == -1)
    {
        trajNextPoint[0] = kTraj[1];
        trajNextPoint[1] = kTraj[2];
        trajNextPoint[2] = kTraj[3];
    }

    Vec3f trajDirection;
    vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);
    f32 dirMag = vec3_mag(trajDirection);
    
    static f32 vl = 11.f;
    #if 0
    static int time = 0;
    if (gPlayer1Controller->buttonPressed & R_JPAD)
    {
        vl += 0.00001f;
    }
    if (gPlayer1Controller->buttonPressed & L_JPAD)
    {
        vl -= 0.00001f;
    }
    if (time != gGlobalTimer)
    {
        print_text_fmt_int(20, 20, "%d", (int) (vl * 10000));
        time = gGlobalTimer;
    }
    #endif

    o->oForwardVel = vl;
    f32 movAmt = o->oForwardVel / dirMag;
    o->oWfTrajProgress += movAmt;
    if (o->oWfTrajProgress >= 1.f)
    {
        o->oWfTrajProgress = o->oWfTrajProgress - 1.f;
        o->oWfTrajCurPoint++;
        if (-1 == traj[4])
        {
            o->oWfTrajCurPoint = 0;
        }
    }
    
    {
        traj = &kTraj[4 * o->oWfTrajCurPoint];
        Vec3f trajCurrPoint = { traj[1], traj[2], traj[3] };
        Vec3f trajNextPoint = { traj[5], traj[6], traj[7] };
        if (-1 == traj[4])
        {
            trajNextPoint[0] = kTraj[1];
            trajNextPoint[1] = kTraj[2];
            trajNextPoint[2] = kTraj[3];
        }

        Vec3f trajDirection;
        vec3f_diff(trajDirection, trajNextPoint, trajCurrPoint);
        o->oPosX = trajCurrPoint[0] + (trajDirection[0] * o->oWfTrajProgress);
        o->oPosY = trajCurrPoint[1] + (trajDirection[1] * o->oWfTrajProgress);
        o->oPosZ = trajCurrPoint[2] + (trajDirection[2] * o->oWfTrajProgress);
    }
}
