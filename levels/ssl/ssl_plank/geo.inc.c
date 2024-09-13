#include "src/game/envfx_snow.h"

const GeoLayout ssl_plank_geo[] = {
    GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_plank_Plane_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
