#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t pos) {
    float d = sqrt(pos.x * pos.x + pos.y * pos.y);

    return d <= 1 ? 10 : d <= 5 ? 5 : d <= 10;
}
