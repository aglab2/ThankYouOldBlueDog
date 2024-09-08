#ifndef WF_HEADER_H
#define WF_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const struct MovtexQuadCollection wf_movtex_water[];

// script
extern const LevelScript level_wf_entry[];

#include "levels/wf/header.inc.h"

#include "levels/wf/wf_movesafe/collision_header.h"

#include "levels/wf/wf_movesafe/geo_header.h"

#include "levels/wf/wf_movedeath/geo_header.h"

#include "levels/wf/wf_movedeath/collision_header.h"

#endif
