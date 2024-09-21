#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/rr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_rr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _rr_segment_7SegmentRomStart, _rr_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_CUBE, rr_cube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_MOVE, rr_move_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_ROTAT, rr_rotat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_JUMP_0, rr_jump_0_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_JUMP_1, rr_jump_1_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rr_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 184, 85, -3260, 0, 0, 0, 0x00000000, bhvRrCtl),
		OBJECT(MODEL_NONE, 12672, -87, 12933, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		OBJECT(MODEL_NONE, 11368, 839, 12933, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		MARIO_POS(0x01, 0, 1799, 192, 925),
		OBJECT(MODEL_NONE, 3090, 897, -13100, 0, -90, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_RR_MOVE, 13095, 0, -13127, 0, -90, 0, 0x00000000, bhvRrMove),
		OBJECT(MODEL_RR_CUBE, 1985, -162, 12910, 0, 0, 0, 0x00000000, bhvRrCube),
		OBJECT(MODEL_RR_JUMP_0, -12437, 0, 12933, 0, 0, 0, 0x00000000, bhvRrJump),
		OBJECT(MODEL_NONE, -14368, 85, -1295, 0, 0, 0, 0x00000000, bhvRrRotatCtl),
		OBJECT(MODEL_NONE, -12434, 85, -14, 0, 0, 0, 0x00000000, bhvRrRotatCtl),
		OBJECT(MODEL_NONE, -13494, 85, 1649, 0, 0, 0, 0x00000000, bhvRrRotatCtl),
		OBJECT(MODEL_NONE, 14534, 85, -13127, 0, -90, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, -10002, 85, -15290, 0, -90, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, -13551, 85, -3224, 0, 0, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, 13399, 85, 3318, 0, -145, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, 15005, 85, 12933, 0, -90, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, 3479, 85, 12933, 0, -90, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, -9389, 85, 12933, 0, -90, 0, 0x00000000, bhvRrStart),
		OBJECT(MODEL_NONE, 1127, -2985, -3426, 0, 0, 0, 0x00000000, bhvRrStart),
		TERRAIN(rr_area_1_collision),
		MACRO_OBJECTS(rr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_NOVEL),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 1799, 192, 925),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
