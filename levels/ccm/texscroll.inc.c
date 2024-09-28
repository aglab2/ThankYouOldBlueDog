void scroll_gfx_ccm_dl_Plane_003_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(ccm_dl_Plane_003_mesh_layer_1);

	shift_s(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_ccm_dl_Plane_009_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(ccm_dl_Plane_009_mesh_layer_1);

	shift_s(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_ccm() {
	scroll_gfx_ccm_dl_Plane_003_mesh_layer_1();
	scroll_gfx_ccm_dl_Plane_009_mesh_layer_1();
};
