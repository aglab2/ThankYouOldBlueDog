void scroll_rr_dl_ow_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_001_mesh_layer_5_vtx_0);

	deltaY = (int)(0.12999999523162842 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_001_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_001_mesh_layer_5_vtx_1);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_003_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_003_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_005_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_005_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_007_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_007_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_Sphere_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_001_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_002_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_002_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_003_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_004_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_005_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_005_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_006_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_006_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_007_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1722;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_007_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr_dl_Sphere_008_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1730;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_Sphere_008_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_rr() {
	scroll_rr_dl_ow_001_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_001_mesh_layer_5_vtx_1();
	scroll_rr_dl_ow_003_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_005_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_007_mesh_layer_5_vtx_0();
	scroll_rr_dl_Sphere_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_001_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_002_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_003_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_004_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_005_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_006_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_007_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_008_mesh_layer_1_vtx_0();
};
