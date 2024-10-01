#include "buffers/buffers.h"

extern Gfx mat_wmotr_dl_f3dlite_material_layer1[];
extern Gfx mat_wmotr_dl_f3dlite_material_001[];

struct Color
{
    u8 r, g, b, a;
};

extern struct Color get_flower_middle_color(int saveFile, int fromFileSelect);

void bhv_wmotr_init()
{
    save_file_seal_check(gCurrSaveFileNum - 1);
    struct Color color = get_flower_middle_color(gCurrSaveFileNum - 1, 0);

    u8* ptr = segmented_to_virtual(mat_wmotr_dl_f3dlite_material_layer1);
    ptr[5*8 + 4] = color.r;
    ptr[5*8 + 5] = color.g;
    ptr[5*8 + 6] = color.b;

    if (0 == gSaveBuffer.files[gCurrSaveFileNum - 1][0].tampers)
    {
        u8* ptr = segmented_to_virtual(mat_wmotr_dl_f3dlite_material_001);
        ptr[1*8 + 4] = 0xDC * 0.25f;
        ptr[1*8 + 5] = 0x14 * 0.25f;
        ptr[1*8 + 6] = 0x3C * 0.25f;
    }

    set_gravity(0);
    gDisableGravity = 0;
    gFizzle = 0;
}
