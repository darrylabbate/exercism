#include "nucleotide_count.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNTSTR "A:%d C:%d G:%d T:%d"

char *count(const char *dna_strand) {
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;

    bool invalid = false;

    char *ncount = calloc(1, 50);

    while (*dna_strand) {
        switch(*dna_strand++) {
        case 'A': a++; break;
        case 'C': c++; break;
        case 'G': g++; break;
        case 'T': t++; break;
        default: invalid = true; break;
        }
    }

    if (!invalid) {
        sprintf(ncount, COUNTSTR, a, c, g, t);
    }

    return ncount;
}
