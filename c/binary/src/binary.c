#include "binary.h"
#include <string.h>

int convert(const char *input) {
    int x = 0;
    int e = strlen(input) - 1;
    while (*input) {
        switch (*input++) {
        case '0': e--; break;
        case '1': x += 1 << e--; break;
        default: return INVALID;
        }
    }
    return x;
}
