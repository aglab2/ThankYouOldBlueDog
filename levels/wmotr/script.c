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
#include "levels/wmotr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wmotr_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_WMOTR, 0x01, 0xf0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_WMOTR, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x23, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x24, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x25, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x26, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x27, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x28, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x29, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2a, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2b, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2C, LEVEL_RR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 1265, 0),
		OBJECT(MODEL_NONE, 6, 1265, 4, 0, 0, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -1807, 738, -1365, 0, 0, 0, (0x21 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -1021, 744, -1879, 0, 0, 0, (0x22 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 32, 739, -2237, 0, 0, 0, (0x23 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1084, 731, -1961, 0, 0, 0, (0x24 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1848, 739, -1277, 0, 0, 0, (0x25 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 2388, 740, -211, 0, 0, 0, (0x26 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 2134, 720, 1179, 0, 0, 0, (0x27 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1327, 727, 1869, 0, 0, 0, (0x28 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -256, 735, 2267, 0, 0, 0, (0x29 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -1360, 701, 1617, 0, 0, 0, (0x2A << 16), bhvWarp),
		OBJECT(MODEL_NONE, -1982, 701, 854, 0, 0, 0, (0x2B << 16), bhvWarp),
		OBJECT(MODEL_NONE, -2464, 734, -284, 0, 0, 0, (0x2C << 16), bhvWarp),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 1265, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
