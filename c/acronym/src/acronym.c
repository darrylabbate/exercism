#include "acronym.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXPHRASE 256

char *abbreviate(const char *phrase) {
    if (phrase == NULL)
        return NULL;

    char *a = calloc(1,20);

    while (*phrase) {
        switch (*phrase++) {
        case ' ': sprintf(a++, "%c", toupper(*(++phrase))); break;
        case '-': sprintf(a++, "%c", toupper(*(++phrase))); break;
        default: break;
        }
    }

    return a;
}
