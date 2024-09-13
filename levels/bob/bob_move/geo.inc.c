#include "src/game/envfx_snow.h"

// 0x0C000224
const GeoLayout bob_move_geo[] = {
    GEO_CULLING_RADIUS(30000),
    GEO_OPEN_NODE(),
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_move_Plane_002_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_move_Plane_002_mesh_layer_1),
		GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_END(),
};