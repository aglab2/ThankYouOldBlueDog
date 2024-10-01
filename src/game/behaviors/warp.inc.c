// warp.inc.c

void bhv_warp_loop(void) {
    if (o->oTimer == 0) {
        o->hitboxRadius = 150.0f;
        o->hitboxHeight = 200.0f;
        o->hitboxDownOffset += 100.f;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

// identical to the above function except for o->hitboxRadius
void bhv_fading_warp_loop() {
    if (o->oTimer == 0) {
        o->hitboxRadius = 500.0f;
        o->hitboxHeight = 100.0f;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}
