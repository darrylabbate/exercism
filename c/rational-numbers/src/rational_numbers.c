#include "rational_numbers.h"
#include <math.h>

rational_t add(rational_t r1, rational_t r2) {
    int16_t n = r1.numerator * r2.denominator 
              + r2.numerator * r1.denominator;
    int16_t d = !n ? 1 : r1.denominator * r2.denominator;
    return reduce((rational_t) {n,d});
}

rational_t subtract(rational_t r1, rational_t r2) {
    int16_t n = r1.numerator * r2.denominator 
              - r2.numerator * r1.denominator;
    int16_t d = !n ? 1 : r1.denominator * r2.denominator;
    return reduce((rational_t) {n,d});
}

rational_t multiply(rational_t r1, rational_t r2) {
    int16_t n = r1.numerator   * r2.numerator;
    int16_t d = r1.denominator * r2.denominator;
    return reduce((rational_t) {n,d});
}

rational_t divide(rational_t r1, rational_t r2) {
    int16_t n = r1.numerator * r2.denominator;
    int16_t d = r2.numerator * r1.denominator;
    return reduce((rational_t) {n,d});
}

rational_t absolute(rational_t r) {
    int16_t n_sign = r.numerator   >> 15;
    int16_t d_sign = r.denominator >> 15;
    int16_t n = (r.numerator   + n_sign) ^ n_sign;
    int16_t d = (r.denominator + d_sign) ^ d_sign;
    return reduce((rational_t) {n,d});
}

rational_t exp_rational(rational_t r, uint16_t n) {
    if (!n)           return (rational_t) {1,1};
    if (!r.numerator) return (rational_t) {0,1};

    int16_t n1 = pow(r.numerator,   n);
    int16_t d1 = pow(r.denominator, n);
    return reduce((rational_t) {n1,d1});
}

static float nth_root(float x, float n) {
    return pow(x, 1.0 / n);
}

float exp_real(uint16_t n, rational_t r) {
    if (!r.numerator) return 1.0;
    r = reduce(r);
    float p = pow(n, r.numerator);
    return nth_root(p, r.denominator);
}

static int16_t gcd(int16_t x, int16_t y) {
    int16_t t;
    while (y) {
        t = y;
        y = x % y;
        x = t;
    }
    return x;
}

rational_t reduce(rational_t r) {
    if (!r.numerator) return (rational_t) {0,1};

    int16_t x = gcd(r.numerator, r.denominator);
    int16_t n = r.numerator   / x;
    int16_t d = r.denominator / x;

    return d < 0 ? (rational_t) {-n,-d} 
                 : (rational_t) { n, d};
}
