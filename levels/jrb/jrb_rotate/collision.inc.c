const Collision jrb_rotate_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(1770, -2, -257),
	COL_VERTEX(1537, -2, -915),
	COL_VERTEX(1070, -2, -1433),
	COL_VERTEX(440, -2, -1734),
	COL_VERTEX(-257, -2, -1770),
	COL_VERTEX(-915, -2, -1537),
	COL_VERTEX(-1433, -2, -1070),
	COL_VERTEX(-1734, -2, -440),
	COL_VERTEX(-1770, -2, 257),
	COL_VERTEX(-1537, -2, 915),
	COL_VERTEX(-1070, -2, 1433),
	COL_VERTEX(-440, -2, 1734),
	COL_VERTEX(257, -2, 1770),
	COL_VERTEX(915, -2, 1537),
	COL_VERTEX(1433, -2, 1070),
	COL_VERTEX(1734, -2, 440),
	COL_TRI_INIT(SURFACE_DEFAULT, 14),
	COL_TRI(0, 1, 2),
	COL_TRI(2, 3, 4),
	COL_TRI(4, 5, 6),
	COL_TRI(6, 7, 8),
	COL_TRI(8, 9, 10),
	COL_TRI(10, 11, 12),
	COL_TRI(12, 13, 14),
	COL_TRI(14, 15, 0),
	COL_TRI(0, 2, 4),
	COL_TRI(4, 6, 8),
	COL_TRI(8, 10, 12),
	COL_TRI(12, 14, 0),
	COL_TRI(0, 4, 8),
	COL_TRI(8, 12, 0),
	COL_TRI_STOP(),
	COL_END()
};
