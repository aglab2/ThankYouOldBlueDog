void scroll_ddd_dl_cosmic_001_mesh_layer_1_vtx_7() {
	int i = 0;
	int count = 470;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_cosmic_001_mesh_layer_1_vtx_7);

	deltaY = (int)(-0.23000001907348633 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_Plane_001_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Plane_001_mesh_layer_4_vtx_0);

	deltaY = (int)(0.1599999964237213 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd() {
	scroll_ddd_dl_cosmic_001_mesh_layer_1_vtx_7();
	scroll_ddd_dl_Plane_001_mesh_layer_4_vtx_0();
};
