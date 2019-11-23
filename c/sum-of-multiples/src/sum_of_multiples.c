#include "sum_of_multiples.h"

unsigned int sum_of_multiples(const unsigned int *multiples,
                              const size_t number_of_multiples,
                              const unsigned int up_to) {
    unsigned int sum = 0;
    if (!multiples) return sum;
    for (unsigned int i = 1; i < up_to; i++) {
        for (size_t j = 0; j < number_of_multiples; j++) {
            if (multiples[j] && !(i % multiples[j])) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}
