#include "clz-bsrch.h"

static uint8_t clz(uint32_t x)
{
    if (x == 0) return 32;
    uint8_t n = 0;
    if (x <= 0x0000FFFF) {
        n += 16;
        x <<= 16;
    }
    if (x <= 0x00FFFFFF) {
        n += 8;
        x <<= 8;
    }
    if (x <= 0x0FFFFFFF) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3FFFFFFF) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7FFFFFFF) {
        n += 1;
        x <<= 1;
    }
    return n;
}

const clz_obj clz_bsrch_obj = {
    .clz = clz,
    .name = CLZ_BSRCH
};
