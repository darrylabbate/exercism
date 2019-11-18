#include "armstrong_numbers.h"
#include <math.h>

static int digits(int candidate) {
    int d = 0;
    while (candidate > 0) {
        candidate /= 10;
        ++d;
    }
    return d;
}

int is_armstrong_number(int candidate) {
    int e = digits(candidate);
    int n = candidate;
    int s = 0;

    while (n > 0) {
        s += pow(n % 10, e);
        n /= 10;
    }
    return (candidate < 10) || (s == candidate);
}
