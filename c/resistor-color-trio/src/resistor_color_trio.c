#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t *colors) {
    resistor_value_t resistor = {0,0};
    uint64_t t = (colors[0] * 10 + colors[1]) * pow(10, colors[2]);

    while (t / 1000 >= 1) {
        ++resistor.unit;
        t /= 1000;
    }

    resistor.value = t;
    return resistor;
}
