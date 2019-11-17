#include "hamming.h"
#include <stddef.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (!lhs || !rhs || !(strlen(lhs) == strlen(rhs)))
        return -1;

    int distance = 0;
    int l = (int)strlen(lhs);
    for(int i=0; i<l; i++)
        if(lhs[i] != rhs[i])
            distance++;
    return distance;
}
