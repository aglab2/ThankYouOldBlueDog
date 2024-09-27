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
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0xa, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_0, wdw_0_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_1, wdw_1_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YELLOW_COIN, -277, -56, -3807, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3313, 259, 568, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, -234, 1419, -774, 0, 0, 0, (0x11 << 16), bhvCoinFormation),
		MARIO_POS(0x01, 0, 0, 499, -14),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvWdwCtl),
		OBJECT(MODEL_NONE, -3, 506, -28, 0, -90, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, -234, 2129, -774, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(wdw_area_1_collision),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WORKING),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 499, -14),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
