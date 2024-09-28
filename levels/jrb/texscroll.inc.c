void scroll_jrb_dl_3_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 48;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_3_mesh_layer_1_vtx_2);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_Circle_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 224;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Circle_002_mesh_layer_5_vtx_0);

	deltaY = (int)(0.3400000333786011 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_3_001_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 48;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_3_001_mesh_layer_1_vtx_2);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_Circle_004_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 224;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Circle_004_mesh_layer_5_vtx_0);

	deltaY = (int)(0.3400000333786011 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb() {
	scroll_jrb_dl_3_mesh_layer_1_vtx_2();
	scroll_jrb_dl_Circle_002_mesh_layer_5_vtx_0();
	scroll_jrb_dl_3_001_mesh_layer_1_vtx_2();
	scroll_jrb_dl_Circle_004_mesh_layer_5_vtx_0();
};
