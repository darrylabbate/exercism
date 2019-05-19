#include "pangram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

#define eval(x) ((x) & 0x3FFFFFF) == 0x3FFFFFF

static bool iter(int i, uint32_t u, const char *sentence)
{
  if (isalpha(sentence[i])) {
    uint32_t l = 1 << (toupper(sentence[i]) - 'A');
    return eval(u | l) ? true : iter(i + 1, u |= l, sentence);
  }
  return sentence[i] == '\0' ? eval(u) : iter(i + 1, u, sentence);
}

bool is_pangram(const char *sentence)
{
  return sentence == NULL ? false : iter(0, 0, sentence);
}
