#include "pythagorean_triplet.h"
#include <stdbool.h>

static bool eval(uint16_t a, uint16_t b, uint16_t c) {
    return a * a + b * b == c * c;
}

static triplets_t *add_triplet(triplets_t *t, uint16_t a, uint16_t b, uint16_t c) {
    size_t count = t->count;
    triplets_t *new = realloc(t, sizeof(triplets_t) + sizeof(triplet_t) * ++count);
    t = new;
    t->triplets[count - 1] = (triplet_t) {a, b, c};
    t->count = count;
    return t;
}

triplets_t *triplets_with_sum(uint16_t sum) {
    triplets_t *t = malloc(sizeof(triplets_t));
    t->count = 0;
    for (uint16_t a = 1; a < sum / 3; a++) {
        for (uint16_t b = a; b < sum / 2; b++) {
            uint16_t c = sum - (a + b);
            if (eval(a, b, c)) t = add_triplet(t, a, b, c);
        }
    }
    return t;
}

void free_triplets(triplets_t *triplets) {
    free(triplets);
}
