#include "bob.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SILENCE      "Fine. Be that way!"
#define NORMAL       "Whatever."
#define YELL         "Whoa, chill out!"
#define QUESTION     "Sure."
#define YELLQUESTION "Calm down, I know what I'm doing!"

static char *trim(char *str) {
    char *x = calloc(1, strlen(str) + 1);
    int i = 0;
    while (*str) {
        switch (*str) {
        case ' ':
        case '\n':
        case '\r':
        case '\t': str++; break;
        default:   x[i++] = *str++; break;
        }
    }
    return x;
}

static bool yell(char *greeting) {
    for (size_t i = 0; i < strlen(greeting); i++) {
        if (isupper(greeting[i]))
            return isupper(greeting[i]) && isupper(greeting[i + 1]);
    }
    return false;
}

static bool question(char *greeting) {
    return greeting[strlen(greeting) - 1] == '?';
}

char *hey_bob(char *greeting) {
    greeting = trim(greeting);
    if (!*greeting)
        return SILENCE;
    else if (yell(greeting) && question(greeting))
        return YELLQUESTION;
    else if (yell(greeting))
        return YELL;
    else if (question(greeting))
        return QUESTION;
    else
        return NORMAL;
}
