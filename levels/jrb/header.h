#ifndef JRB_HEADER_H
#define JRB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const struct MovtexQuadCollection jrb_movtex_water[];
extern const struct MovtexQuadCollection jrb_movtex_initial_mist[];
extern const struct MovtexQuadCollection jrb_movtex_sunken_ship_water[];

// script
extern const LevelScript level_jrb_entry[];

#include "levels/jrb/header.inc.h"

#include "levels/jrb/jrb_rotate/geo_header.h"

#include "levels/jrb/jrb_rotate/collision_header.h"

#include "levels/jrb/jrb_box/geo_header.h"

#include "levels/jrb/jrb_box/collision_header.h"

#endif
