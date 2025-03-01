void scroll_bbh_dl_island_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 29;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bbh_dl_island_mesh_layer_1_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bbh_dl_island_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 29;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bbh_dl_island_001_mesh_layer_1_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bbh_dl_island_002_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 29;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bbh_dl_island_002_mesh_layer_1_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bbh_dl_Plane_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 22;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_Plane_001_mesh_layer_5_vtx_0);

	deltaY = (int)(0.04000002145767212 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_dl_Plane_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 917;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_Plane_002_mesh_layer_5_vtx_0);

	deltaY = (int)(0.04000002145767212 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh() {
	scroll_bbh_dl_island_mesh_layer_1_vtx_0();
	scroll_bbh_dl_island_001_mesh_layer_1_vtx_0();
	scroll_bbh_dl_island_002_mesh_layer_1_vtx_0();
	scroll_bbh_dl_Plane_001_mesh_layer_5_vtx_0();
	scroll_bbh_dl_Plane_002_mesh_layer_5_vtx_0();
};
