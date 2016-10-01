#include "clz.h"
#include "clz-bsrch.h"
#include "clz-bshift.h"
#include "clz-harley.h"
#include "clz-iter.h"
#include "clz-rcs.h"
#include <string.h>

static const clz_obj *clz_objects[] = {
    &clz_bsrch_obj,
    &clz_bshift_obj,
    &clz_harley_obj,
    &clz_iter_obj,
    &clz_rcs_obj,
};

const clz_obj *get_clz_object(const char* name)
{
    int i = 0;
    for (i = 0; i < sizeof(clz_objects)/sizeof(clz_objects[0]); i++) {
        if (!strcmp(name, clz_objects[i]->name))
            return clz_objects[i];
    }
    return NULL;
}

int test_clz(const clz_obj *obj, uint32_t begin, uint32_t end)
{
    uint32_t i = 0;

    for (i = begin; i < end; i++)
        obj->clz(i);
}
