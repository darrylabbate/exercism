#include "word_count.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int word_count(const char *input_text, word_count_word_t *words) {
    char *input_text_lower = calloc(1, strlen(input_text) + 1);
    int i = 0;
    while (*input_text)
        input_text_lower[i++] = (isalpha(*input_text)) ? tolower(*input_text++) : *input_text++;
    input_text = input_text_lower;

    int n = 0;

    const char *delims = " ,.-\n:!!&@$%^&\"";
    char *word = strtok(input_text, delims);
    while (word != NULL) {
        word = strtok(NULL, delims);
    }

    return n;
}
