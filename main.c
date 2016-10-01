#include "clz.h"
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void usage(FILE *stream)
{
    fprintf(stream, "Usage: clz {-m|--method} <method> [options]\n");
    fprintf(stream, "Options:\n");
    fprintf(stream, "  {-h|--help}\n");
    fprintf(stream, "  {-b|--begin} <value>\n");
    fprintf(stream, "  {-e|--end} <value>\n");
    fprintf(stream, "Methods:\n");
    fprintf(stream, "  {bsrch|bshift|harley|iter|rcs}\n");
}

int strtou32_safe(const char *str, uint32_t *out)
{
    char *endptr = NULL;
    unsigned long tmp;

    if (!str || !out)
        return -1;
    errno = 0;
    tmp = strtoul(str, &endptr, 10);
    if (endptr == str || errno == ERANGE)
        return -1;
    *out = (uint32_t)tmp;
    return 0;
}

int main(int argc, char *argv[])
{
    const char shortopts[] = "hb:e:m:";
    const struct option longopts[] = {
        {"help", no_argument, NULL, 'h'},
        {"begin", required_argument, NULL, 'b'},
        {"end", required_argument, NULL, 'e'},
        {"method", required_argument, NULL, 'm'}
    };
    const clz_obj *obj = NULL;
    uint32_t begin = 0;
    uint32_t end = UINT32_MAX;
    int ch = 0;

    while ((ch = getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
        switch (ch) {
            case 'h':
                usage(stdout);
                return 0;
            case 'b':
                if (strtou32_safe(optarg, &begin) < 0)
                    return 1;
                break;
            case 'e':
                if (strtou32_safe(optarg, &end) < 0)
                    return 1;
                break;
            case 'm':
                obj = get_clz_object(optarg);
                break;
            default:
                usage(stderr);
                return 1;
        }
    }
    if (!obj) {
        usage(stderr);
        return 1;
    }

    test_clz(obj, begin, end);
}
