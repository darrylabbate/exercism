#include "beer_song.h"
#include <stdio.h>
#include <string.h>

#define ZERO_VERSE "No more bottles of beer on the wall, no more bottles of beer.\n"\
                   "Go to the store and buy some more, 99 bottles of beer on the wall.\n"
#define ONE_VERSE  "1 bottle of beer on the wall, 1 bottle of beer.\n"\
                   "Take it down and pass it around, no more bottles of beer on the wall.\n"
#define TWO_VERSE  "2 bottles of beer on the wall, 2 bottles of beer.\n"\
                   "Take one down and pass it around, 1 bottle of beer on the wall.\n"
#define N_VERSE    "%d bottles of beer on the wall, %d bottles of beer.\n"\
                   "Take one down and pass it around, %d bottles of beer on the wall.\n"

void verse(char *buffer, unsigned int v) {
    switch (v) {
    case 0:  sprintf(buffer, ZERO_VERSE);         break;
    case 1:  sprintf(buffer, ONE_VERSE);          break;
    case 2:  sprintf(buffer, TWO_VERSE);          break;
    default: sprintf(buffer, N_VERSE, v, v, v-1); break;
    }
}
void sing(char *buffer, unsigned int s, unsigned int e) {
    char *p = buffer;
    while (s > e) {
        verse(p, s--);
        while (*p) ++p;
        strcpy(p++, "\n");
    }
    verse(p, s);
}
