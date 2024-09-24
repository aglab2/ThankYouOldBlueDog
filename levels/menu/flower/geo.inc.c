#include "src/game/envfx_snow.h"

const GeoLayout flower_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_000_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_leaves_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flower_middle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
