#include "rna_transcription.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
    bool invalid = false;
    char *rna = calloc(1, strlen(dna));
    int i = 0;
    while (*dna) {
        switch (*dna++) {
        case 'G': rna[i++] = 'C'; break;
        case 'C': rna[i++] = 'G'; break;
        case 'T': rna[i++] = 'A'; break;
        case 'A': rna[i++] = 'U'; break;
        default:  invalid = true; break;
        }
    }
    return !invalid ? rna : NULL;
}
