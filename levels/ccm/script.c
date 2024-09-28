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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -3, 952, 64, 0, -90, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -12, -3242, -2429, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		OBJECT(MODEL_STAR, -39, 319, -6469, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -12, 2630, -5368, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		OBJECT(MODEL_YELLOW_COIN, 0, 856, -747, 0, 0, 0, 0x00000000, bhvOneCoin),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WHOA),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YELLOW_COIN, 0, 856, -747, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, 0, 1053, -5367, 0, 0, 0, 0x00000000, bhvCcmUp),
		OBJECT(MODEL_NONE, 0, -439, -3441, 0, 0, 0, 0x00000000, bhvCcmUp),
		OBJECT(MODEL_NONE, 0, 875, -407, 0, 0, 0, 0x00000000, bhvCcmUp),
		OBJECT(MODEL_NONE, 0, 1053, -4465, 0, 0, 0, 0x00000000, bhvCcmUp),
		OBJECT(MODEL_STAR, -39, 319, -6469, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -3, 952, 64, 0, -90, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -70, 1049, -16, 0, -90, 0, 0x00000000, bhvCcmUpReset),
		TERRAIN(ccm_area_2_collision),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WHOA),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
