#include "anagram.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define CAND candidates->candidate[i]

static int cmpstr(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

static int eval(char *a, char *b) {
    if (strlen(a) != strlen(b))
        return 0;

    char *a_upper = calloc(1, strlen(a));
    char *b_upper = calloc(1, strlen(b));

    int i = 0;
    while (*a)
        a_upper[i++] = (isalpha(*a)) ? toupper(*a++) : *a++;

    i = 0;
    while (*b)
        b_upper[i++] = (isalpha(*b)) ? toupper(*b++) : *b++;

    a = a_upper;
    b = b_upper;

    if (!memcmp(a, b, strlen(a)))
        return 0;

    qsort(a, strlen(a), sizeof(char), cmpstr);
    qsort(b, strlen(b), sizeof(char), cmpstr);

    return !memcmp(a, b, strlen(a));
}

void anagrams_for(const char *word, struct candidates *candidates) {
    char *a = calloc(1, strlen(word));
    strcpy(a, word);
    for (size_t i = 0; i < candidates->count; i++) {
        if (CAND.is_anagram == UNCHECKED) {
            char *b = calloc(1, strlen(CAND.candidate));
            strcpy(b, CAND.candidate);
            CAND.is_anagram = eval(a, b);
        }
    }
}
