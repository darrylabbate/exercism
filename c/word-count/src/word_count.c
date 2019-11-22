#include "word_count.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static char *strip_quotes(char *word) {
    if ((word[0] == '\'') && (word[strlen(word) - 1] == '\'')) {
        word[strlen(word) - 1] = '\0';
        ++word;
    }
    return word;
}

static bool existing_word(char *word, int n, word_count_word_t *words) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(word, words[i].text)) {
            words[i].count++;
            return true;
        }
    }
    return false;
}

int word_count(const char *input_text, word_count_word_t *words) {
    char *input_text_lower = calloc(1, strlen(input_text) + 1);
    int i = 0;
    while (*input_text)
        input_text_lower[i++] = (isalpha(*input_text)) ? tolower(*input_text++) : *input_text++;

    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

    int n = 0;

    const char *delims = " ,.-\n:!!&@$%^&\"";
    char *word = strtok(input_text_lower, delims);
    while (word != NULL) {
        word = strip_quotes(word);
        if (!existing_word(word, n, words)) {
            if (strlen(word) > MAX_WORD_LENGTH)
                return EXCESSIVE_LENGTH_WORD;
            if (n == MAX_WORDS)
                return EXCESSIVE_NUMBER_OF_WORDS;
            words[n].count = 1;
            strcpy(words[n].text, word);
            n++;
        }
        word = strtok(NULL, delims);
    }
    return n;
}
