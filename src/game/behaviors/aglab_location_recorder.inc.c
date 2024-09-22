#if 0
struct Pos{ f32 x, y, z; };
int sRecCursor = 0;
struct Pos sRecPositions[200];

void record_on_frame()
{
    if (0 == (o->oTimer % 10))
    {
        sRecPositions[sRecCursor].x = gMarioStates->pos[0];
        sRecPositions[sRecCursor].y = gMarioStates->pos[1] + 40.f;
        sRecPositions[sRecCursor].z = gMarioStates->pos[2];
        sRecCursor++;
    }

    print_text_fmt_int(20, 20, "%d", sRecCursor);
}
#endif
