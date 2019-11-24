#include "binary_search.h"

int *binary_search(int v, const int *arr, size_t l) {
    if (!arr || !l) return NULL;
    return v >  arr[l/2] ? binary_search(v, arr + (l-(l/2))/2 + 1, l/2+1) :
           v <  arr[l/2] ? binary_search(v, arr, l/2)       :
           v == arr[l/2] ? (int *)&arr[l/2] : NULL;
}
