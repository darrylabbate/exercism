#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

static int   dec[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
static char *rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char *to_roman_numeral(unsigned int number) {
    char *roman = calloc(1,7);
    for (int i = 0; i < 13; i++) {
        while (number % dec[i] < number) {
            strcat(roman, rom[i]);
            number -= dec[i];
        }
    }
    return roman;
}
