#ifndef __CLZ_H
#define __CLZ_H

#include <stdint.h>

typedef struct {
    uint8_t (*clz)(uint32_t);
    const char *name;
} clz_obj;

const clz_obj *get_clz_object(const char *name);
int test_clz(const clz_obj *obj, uint32_t begin, uint32_t end);

#endif
