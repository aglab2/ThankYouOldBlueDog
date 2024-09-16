#include "src/game/envfx_snow.h"

const GeoLayout rr_jump_1_geo[] = {
    GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_jump_1_Plane_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
