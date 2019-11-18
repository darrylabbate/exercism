#include "square_root.h"

int squareRoot(int n) {
    if (n < 2) return n;

    int s = squareRoot(n >> 2) << 1;
    int l = s + 1;

    return l * l > n ? s : l;
}
