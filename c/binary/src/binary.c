#include "binary.h"

int convert(const char *input) {
    int x = 0;
    while (*input) {
        x <<= 1;
        switch (*input++) {
        case '1': ++x;
        case '0': break;
        default: return INVALID;
        }
    }
    return x;
}
