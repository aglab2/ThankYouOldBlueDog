#include "src/game/envfx_snow.h"

const GeoLayout wdw_1_geo[] = {
    GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wdw_1_Plane_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wdw_1_Plane_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
