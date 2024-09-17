void scroll_gfx_mat_lll_dl_f3dlite_material_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_f3dlite_material_002_layer1);

	shift_s(mat, 19, PACK_TILESIZE(0, 3));
	shift_t(mat, 19, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_lll_dl_f3dlite_material_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_f3dlite_material_001_layer1);

	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_lll() {
	scroll_gfx_mat_lll_dl_f3dlite_material_002_layer1();
	scroll_gfx_mat_lll_dl_f3dlite_material_001_layer1();
};
