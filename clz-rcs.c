#include "clz-rcs.h"

static uint8_t clz(uint32_t x)
{
    /* shift upper half down, rest is filled up with 0s */
    uint16_t upper = (x >> 16);
    // mask upper half away
    uint16_t lower = (x & 0xFFFF);
    return upper ? clz(upper) : 16 + clz(lower);
}

clz_obj clz_rcs_obj = {
    .clz = clz,
    .name = CLZ_RCS
};
