void scroll_wf_dl_Circle_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 275;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Circle_mesh_layer_5_vtx_0);

	deltaY = (int)(0.10000000894069672 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_Circle_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 275;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Circle_001_mesh_layer_5_vtx_0);

	deltaY = (int)(0.10000000894069672 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf() {
	scroll_wf_dl_Circle_mesh_layer_5_vtx_0();
	scroll_wf_dl_Circle_001_mesh_layer_5_vtx_0();
};
