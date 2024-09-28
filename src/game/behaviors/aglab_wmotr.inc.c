extern Gfx mat_wmotr_dl_f3dlite_material_layer1[];

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

    set_gravity(0);
    gDisableGravity = 0;
}
