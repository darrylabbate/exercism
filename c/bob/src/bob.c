#include "bob.h"
#include <stdbool.h>

#define SILENCE      "Fine. Be that way!"
#define NORMAL       "Whatever."
#define YELL         "Whoa, chill out!"
#define QUESTION     "Sure."
#define YELLQUESTION "Calm down, I know what I'm doing!"

static bool yell(char *greeting) {
}

static bool question(char *greeting) {
}

char *hey_bob(char *greeting) {
    if (yell(greeting) && question(greeting))
        return YELLQUESTION;
    else if (yell(greeting))
        return YELL;
    else if (question(greeting))
        return QUESTION;
}
