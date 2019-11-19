#include "acronym.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
    if (phrase == NULL || strlen(phrase) == 0)
        return NULL;

    char *a = calloc(1, strlen(phrase));
    int   i = 0;

    a[i++] = toupper(*phrase++);

    while (*phrase) {
        switch (*phrase++) {
        case ' ': a[i++] = toupper(*phrase); break;
        case '-': a[i++] = toupper(*phrase); break;
        default: break;
        }
    }

    return a;
}
