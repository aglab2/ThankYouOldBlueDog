#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"

#include "make_const_nonconst.h"
#include "levels/rr/areas/1/trajectory.inc.c"

#include "levels/rr/leveldata.inc.c"

#include "levels/rr/rr_cube/model.inc.c"
#include "levels/rr/rr_cube/collision.inc.c"
#include "levels/rr/rr_move/model.inc.c"
#include "levels/rr/rr_move/collision.inc.c"
#include "levels/rr/rr_rotat/model.inc.c"
#include "levels/rr/rr_rotat/collision.inc.c"
#include "levels/rr/rr_jump_0/model.inc.c"
#include "levels/rr/rr_jump_0/collision.inc.c"
#include "levels/rr/rr_jump_1/collision.inc.c"
#include "levels/rr/rr_jump_1/model.inc.c"

u32 kRrCoinsLocations[] = { 
    0xC52B0B3C, 0x42FA0000, 0xC64BC189, 0xC533F1C0, 0x42FA0000, 0xC64BD5F9, 0xC540C2C4, 0x42FA0000, 0xC64C5291, 0x4662A70C,
    0x42FA0000, 0xC64D3278, 0x465FB44C, 0x42FA0000, 0xC650E0B4, 0x465ECF5C, 0x42FA0000, 0xC65586CC, 0x465D6E16, 0x42E1FAB8,
    0xC658CF2C, 0x465CE166, 0x42D94324, 0xC658D724, 0x465B1939, 0x42C490FA, 0xC658B408, 0x4658FA11, 0x431FAD42, 0xC656DEE4,
    0x4656560D, 0x437FD0EA, 0xC6540BB0, 0x46533D1F, 0x4331FCAB, 0xC650C284, 0x464F39FB, 0x43DA690D, 0xC64DFB2C, 0x464AFABB,
    0x4330677E, 0xC64B38CC, 0x46449280, 0x43A80000, 0xC6488358, 0x463DC76A, 0x441E4000, 0xC6461F68, 0x463865FC, 0x447B4000,
    0xC6481EE0, 0x4632B213, 0x448CA000, 0xC64AE864, 0x462FEF5A, 0x44534000, 0xC64D7B64, 0x462F51C3, 0x433A0000, 0xC64F44C4,
    0x462C539E, 0x41F80000, 0xC64FC765, 0x46286B9E, 0x41F80000, 0xC64FC765, 0x4624839E, 0x41F80000, 0xC64FC765, 0x46209B9E,
    0x41F80000, 0xC64FC765, 0x461CB39E, 0x3F800000, 0xC64FC765, 0xC513F278, 0x435795CA, 0xC654DF76, 0xC5238F30, 0x42FA0000,
    0xC65390FD, 0xC5250834, 0x42FA0000, 0xC64ED879
};
