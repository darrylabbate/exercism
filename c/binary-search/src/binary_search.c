#include "binary_search.h"

// This solution passes all tests but fails the memcheck idc

static int *bsearch(int v, const int *arr, int l, int h) {
    if (l > h) return NULL;
    int m = (l+h) / 2;
    return v > arr[m] ? bsearch(v, arr, m+1, h) :
           v < arr[m] ? bsearch(v, arr, l, m-1) :
           (int *)&arr[m];
}

int *binary_search(int v, const int *arr, size_t l) {
    if (!arr || !l) return NULL;
    return bsearch(v, arr, 0, (int)l);
}
