void scroll_rr_dl_o_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 32;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(rr_dl_o_mesh_layer_5_vtx_0);

	deltaX = (int)(0.550000011920929 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

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

void scroll_rr_dl_ow_009_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_009_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_011_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_011_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_013_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_013_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_ow_015_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rr_dl_ow_015_mesh_layer_5_vtx_0);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_rr_dl_Plane_012_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 276;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(rr_dl_Plane_012_mesh_layer_5_vtx_0);

	deltaX = (int)(0.550000011920929 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_rr_dl_Plane_015_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(rr_dl_Plane_015_mesh_layer_5_vtx_0);

	deltaX = (int)(0.550000011920929 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_rr_dl_Plane_018_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(rr_dl_Plane_018_mesh_layer_1_vtx_0);

	deltaX = (int)(-0.009999999776482582 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_rr_dl_Sphere_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1749;
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
	int count = 1729;
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
	int count = 1727;
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
	int count = 1739;
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
	int count = 1738;
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
	int count = 1713;
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
	int count = 1740;
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
	int count = 1731;
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
	scroll_rr_dl_o_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_001_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_001_mesh_layer_5_vtx_1();
	scroll_rr_dl_ow_003_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_005_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_007_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_009_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_011_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_013_mesh_layer_5_vtx_0();
	scroll_rr_dl_ow_015_mesh_layer_5_vtx_0();
	scroll_rr_dl_Plane_012_mesh_layer_5_vtx_0();
	scroll_rr_dl_Plane_015_mesh_layer_5_vtx_0();
	scroll_rr_dl_Plane_018_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_001_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_002_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_003_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_004_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_005_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_006_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_007_mesh_layer_1_vtx_0();
	scroll_rr_dl_Sphere_008_mesh_layer_1_vtx_0();
};
