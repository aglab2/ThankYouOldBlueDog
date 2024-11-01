#ifndef WDW_HEADER_H
#define WDW_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const struct MovtexQuadCollection wdw_movtex_area1_water[];
extern const struct MovtexQuadCollection wdw_movtex_area2_water[];

// script
extern const LevelScript level_wdw_entry[];

#include "levels/wdw/header.inc.h"

#include "levels/wdw/wdw_0/geo_header.h"

#include "levels/wdw/wdw_0/collision_header.h"

#include "levels/wdw/wdw_1/collision_header.h"

#include "levels/wdw/wdw_1/geo_header.h"

#endif
