#include "clz-iter.h"

static uint8_t clz(uint32_t x)
{
    uint8_t n = 32, c = 16;
    do {
        uint8_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

clz_obj clz_iter_obj = {
    .clz = clz,
    .name = CLZ_ITER
};
