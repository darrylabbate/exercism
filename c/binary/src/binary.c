#include "binary.h"
#include <math.h>
#include <string.h>

int convert(const char *input) {
    int d = 0;
    int e = strlen(input) - 1;
    while (*input) {
        switch (*input++) {
        case '0': e--; break;
        case '1': d += pow(2, e--); break;
        default: return INVALID;
        }
    }
    return d;
}
