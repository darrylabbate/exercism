#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    size_t row, column;
} saddle_point_t;

typedef struct {
    size_t count;
    saddle_point_t points[];
} saddle_points_t;

saddle_points_t *saddle_points(size_t r, size_t c, uint8_t m[][c]);
void free_saddle_points(saddle_points_t *s);

#endif
