#include "raindrops.h"
#include <stdio.h>

char *convert(char result[], int drops) {
    char *i = result;
    if (drops % 3 == 0) {
        sprintf(i, "Pling");
        while (*i) ++i;
    }
    if (drops % 5 == 0) {
        sprintf(i, "Plang");
        while (*i) ++i;
    }
    if (drops % 7 == 0) {
        sprintf(i, "Plong");
        while (*i) ++i;
    }
    if (!*result) {
        sprintf(i, "%d", drops);
    }

    return result;
}
