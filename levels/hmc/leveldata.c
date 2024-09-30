#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"

#include "make_const_nonconst.h"
#include "levels/hmc/texture.inc.c"
#include "levels/hmc/areas/1/painting.inc.c"
#include "levels/hmc/areas/1/trajectory.inc.c"
#include "levels/hmc/areas/1/movtext.inc.c"

#include "levels/hmc/leveldata.inc.c"

u32 kHmcCoinsLocations[] = {
    0x40381DA6, 0x42200000, 0x45AE7B64, 0xC1AA3289, 0x42200000, 0x45ACA75C, 0xC1AA3289, 0x42200000, 0x45A7E6F8, 0xC1AA3289,
    0x42300000, 0x45A19750, 0xC1AA3289, 0x43980000, 0x459839E0, 0xC1AA3289, 0x44310000, 0x458E1470, 0xC1AA3289, 0x44360000,
    0x45837700, 0xC1AA3289, 0x43AE0000, 0x4570C31C, 0x41A24860, 0xC2100000, 0x455D0804, 0x42575FCE, 0xC2400000, 0x454D6D7C,
    0x4259B45E, 0xC3AE0000, 0x45394DC8, 0x42744DF6, 0xC4220000, 0x452A7BA4, 0x426479B9, 0xC4090000, 0x4524EC8C, 0x422F6BF9,
    0xC2700000, 0x451E8FF0, 0x422F6BF9, 0x44060000, 0x45182520, 0x422F6BF9, 0x445C0000, 0x450B1A50, 0x4231C089, 0x44570000,
    0x44F61D91
};
