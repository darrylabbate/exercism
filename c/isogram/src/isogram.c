#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

static bool eval(int i, uint32_t u, const char phrase[]) {
    if (isalpha(phrase[i])) {
        uint32_t m = 1 << (toupper(phrase[i]) - 'A');
        return u & m ? false : eval(++i, u |= m, phrase);
    }
    return phrase[i] == '\0' ? true : eval(++i, u, phrase);
}

bool is_isogram(const char phrase[]) {
    return phrase == NULL ? false : eval(0, 0, phrase);
}
