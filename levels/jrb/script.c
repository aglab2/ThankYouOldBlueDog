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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROTAT, jrb_rotate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_BOX, jrb_box_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 12, 3443),
		OBJECT(MODEL_NONE, -3, 525, 3428, 0, -180, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_PURPLE_SWITCH, 0, -35, 0, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_YELLOW_COIN, 454, 447, 1509, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 952, 369, -297, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -188, 369, -614, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -558, 152, 74, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_JRB_ROTAT, 0, 0, 0, 0, 0, 0, 0x00000000, bhvJrbRotat),
		OBJECT(MODEL_JRB_BOX, 0, 0, -3498, 0, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_STAR, 0, 600, -4093, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_FELI),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 5, 21, 3068),
		OBJECT(MODEL_NONE, 2, 478, 3054, 0, -180, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_PURPLE_SWITCH, 5, -21, 0, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_YELLOW_COIN, 410, 409, 1344, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 853, 339, -265, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -163, 339, -547, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -492, 146, 66, 0, -180, 0, (0xa << 16), bhvOneCoin),
		OBJECT(MODEL_JRB_ROTAT, 5, 11, 0, 0, 0, 0, 0x00000000, bhvJrbRotat),
		OBJECT(MODEL_NONE, 5, 11, -3117, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_STAR, 5, 545, -3647, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_FELI),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 5, 21, 3068),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
