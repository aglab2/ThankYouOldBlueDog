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
		OBJECT(MODEL_RED_COIN, 11716, 925, -13143, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, 184, 85, -3260, 0, 0, 0, 0x00000000, bhvRrCtl),
		OBJECT(MODEL_RED_FLAME, 1087, 616, -12204, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1087, 616, -12440, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 149, 336, -12221, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 149, 336, -12456, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 322, 584, -12979, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 322, 584, -13215, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -288, 402, -13011, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -288, 402, -13246, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1363, 343, -13786, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1363, 343, -14022, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -410, 628, -13814, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -410, 628, -14049, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 12487, 776, -12679, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 12218, 857, -12679, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 11926, 934, -12679, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_NONE, 12672, -87, 12933, 0, 0, 0, 0x00000000, bhvRrFlipper),
		OBJECT(MODEL_NONE, 10899, -2462, 7455, 0, 0, 0, 0x00000000, bhvCcmUpReset),
		OBJECT(MODEL_NONE, 11368, 839, 12933, 0, 0, 0, (1 << 16), bhvRrFlipper),
		MARIO_POS(0x01, 0, -2690, 85, -13135),
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
		OBJECT(MODEL_NONE, 13299, 85, 3387, 0, -145, 0, 0x00000000, bhvRrStart),
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
	MARIO_POS(0x01, 0, -2690, 85, -13135),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
