void scroll_gfx_ssl_dl_Sphere_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(ssl_dl_Sphere_mesh_layer_1);


	shift_s_down(mat, 18, PACK_TILESIZE(0, 2));
	shift_t(mat, 20, PACK_TILESIZE(0, 1));

};

void scroll_ssl() {
	scroll_gfx_ssl_dl_Sphere_mesh_layer_1();
};
