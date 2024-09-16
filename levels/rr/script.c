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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rr_area_1),
		OBJECT(MODEL_NONE, 184, 85, -3260, 0, 0, 0, 0x00000000, bhvRrCtl),
		OBJECT(MODEL_NONE, 13489, -188, 12933, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		OBJECT(MODEL_NONE, 12489, -188, 12933, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		OBJECT(MODEL_NONE, 11489, -188, 12933, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		OBJECT(MODEL_NONE, 10489, -188, 12933, 0, 0, 0, 0x00000000, bhvCcmFlipper),
		MARIO_POS(0x01, 0, -13540, 85, -3364),
		OBJECT(MODEL_NONE, 292, 347, 3176, 0, -180, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_RR_MOVE, 13095, 0, -13127, 0, -90, 0, 0x00000000, bhvRrMove),
		OBJECT(MODEL_RR_CUBE, 1985, -162, 12910, 0, 0, 0, 0x00000000, bhvRrCube),
		OBJECT(MODEL_NONE, -14368, 85, -1295, 0, 0, 0, 0x00000000, bhvRrRotatCtl),
		OBJECT(MODEL_NONE, -12434, 85, -14, 0, 0, 0, 0x00000000, bhvRrRotatCtl),
		OBJECT(MODEL_NONE, -13494, 85, 1649, 0, 0, 0, 0x00000000, bhvRrRotatCtl),
		TERRAIN(rr_area_1_collision),
		MACRO_OBJECTS(rr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -13540, 85, -3364),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
