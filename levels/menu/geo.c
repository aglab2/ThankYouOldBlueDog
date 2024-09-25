#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"
#include "menu/file_select.h"
#include "menu/star_select.h"

#include "make_const_nonconst.h"

#include "levels/menu/header.h"

extern Gfx* geo_flower_leaves(s32 callContext, struct GraphNode *node, UNUSED void *context);

// 0x0E0001D0
const GeoLayout geo_menu_mario_save_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, 0, 0, 0),
         GEO_OPEN_NODE(),
      		GEO_ASM(0, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_000_mesh_layer_1),
      		GEO_ASM(1, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_001_mesh_layer_1),
      		GEO_ASM(2, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_002_mesh_layer_1),
      		GEO_ASM(3, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_003_mesh_layer_1),
      		GEO_ASM(4, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_004_mesh_layer_1),
      		GEO_ASM(5, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_005_mesh_layer_1),
      		GEO_ASM(6, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_006_mesh_layer_1),
      		GEO_ASM(7, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_007_mesh_layer_1),
      		GEO_ASM(8, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_008_mesh_layer_1),
      		GEO_ASM(9, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_009_mesh_layer_1),
      		GEO_ASM(10, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_010_mesh_layer_1),
      		GEO_ASM(11, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_011_mesh_layer_1),
      		GEO_ASM(15, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_middle_mesh_layer_1),
         GEO_CLOSE_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_save_button_back),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000200
const GeoLayout geo_menu_mario_save_button_fade[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, 0, 0, 0),
         GEO_OPEN_NODE(),
      		GEO_ASM(0, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_000_mesh_layer_1),
      		GEO_ASM(1, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_001_mesh_layer_1),
      		GEO_ASM(2, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_002_mesh_layer_1),
      		GEO_ASM(3, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_003_mesh_layer_1),
      		GEO_ASM(4, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_004_mesh_layer_1),
      		GEO_ASM(5, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_005_mesh_layer_1),
      		GEO_ASM(6, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_006_mesh_layer_1),
      		GEO_ASM(7, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_007_mesh_layer_1),
      		GEO_ASM(8, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_008_mesh_layer_1),
      		GEO_ASM(9, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_009_mesh_layer_1),
      		GEO_ASM(10, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_010_mesh_layer_1),
      		GEO_ASM(11, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_011_mesh_layer_1),
      		GEO_ASM(15, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_middle_mesh_layer_1),
         GEO_CLOSE_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_save_button_fade_back),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000230
const GeoLayout geo_menu_mario_new_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, 0, 0, 0),
         GEO_OPEN_NODE(),
      		GEO_ASM(0, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_000_mesh_layer_1),
      		GEO_ASM(1, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_001_mesh_layer_1),
      		GEO_ASM(2, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_002_mesh_layer_1),
      		GEO_ASM(3, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_003_mesh_layer_1),
      		GEO_ASM(4, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_004_mesh_layer_1),
      		GEO_ASM(5, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_005_mesh_layer_1),
      		GEO_ASM(6, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_006_mesh_layer_1),
      		GEO_ASM(7, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_007_mesh_layer_1),
      		GEO_ASM(8, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_008_mesh_layer_1),
      		GEO_ASM(9, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_009_mesh_layer_1),
      		GEO_ASM(10, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_010_mesh_layer_1),
      		GEO_ASM(11, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_011_mesh_layer_1),
      		GEO_ASM(15, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_middle_mesh_layer_1),
         GEO_CLOSE_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_save_button_back),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000260
const GeoLayout geo_menu_mario_new_button_fade[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0,0,0, 0, 0, 0),
         GEO_OPEN_NODE(),
      		GEO_ASM(0, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_000_mesh_layer_1),
      		GEO_ASM(1, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_001_mesh_layer_1),
      		GEO_ASM(2, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_002_mesh_layer_1),
      		GEO_ASM(3, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_003_mesh_layer_1),
      		GEO_ASM(4, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_004_mesh_layer_1),
      		GEO_ASM(5, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_005_mesh_layer_1),
      		GEO_ASM(6, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_006_mesh_layer_1),
      		GEO_ASM(7, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_007_mesh_layer_1),
      		GEO_ASM(8, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_008_mesh_layer_1),
      		GEO_ASM(9, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_009_mesh_layer_1),
      		GEO_ASM(10, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_010_mesh_layer_1),
      		GEO_ASM(11, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_011_mesh_layer_1),
      		GEO_ASM(15, geo_flower_leaves),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_middle_mesh_layer_1),
         GEO_CLOSE_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_save_button_fade_back),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000290
const GeoLayout geo_menu_erase_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_erase_button),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E0002B8
const GeoLayout geo_menu_copy_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_copy_button),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E0002E0
const GeoLayout geo_menu_file_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_file_button),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000308
const GeoLayout geo_menu_score_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_score_button),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000330
const GeoLayout geo_menu_sound_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_sound_button),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000358
const GeoLayout geo_menu_generic_button[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 524288),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, dl_menu_generic_button),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000380
const GeoLayout geo_menu_file_select_strings_and_menu_cursor[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_CENTER_X, SCREEN_CENTER_Y, SCREEN_CENTER_X, SCREEN_CENTER_Y),
   GEO_OPEN_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
            GEO_BACKGROUND_COLOR(0x0001),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM(45, 100, 25000),
         GEO_OPEN_NODE(),
            GEO_CAMERA(CAMERA_MODE_NONE, 0, 0, 1000, 0, 0, 0, 0x00000000),
            GEO_OPEN_NODE(),
               GEO_RENDER_OBJ(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_file_select_strings_and_menu_cursor),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x0E000408
const GeoLayout geo_menu_act_selector_strings[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_CENTER_X, SCREEN_CENTER_Y, SCREEN_CENTER_X, SCREEN_CENTER_Y),
   GEO_OPEN_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
            GEO_BACKGROUND_COLOR(0xFFFF),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM(45, 100, 25000),
         GEO_OPEN_NODE(),
            GEO_CAMERA(CAMERA_MODE_NONE, 0, 0, 1000, 0, 0, 0, 0x00000000),
            GEO_OPEN_NODE(),
               GEO_RENDER_OBJ(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_act_selector_strings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

#include "levels/menu/flower/geo.inc.c"