#include <stddef.h>
#include <string.h>
#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
  int c = -1;
  if (lhs && rhs && (strlen(lhs) == strlen(rhs))) {
    c = 0;
    int l = (int)strlen(lhs);
    for(int i=0; i<l; i++)
      if(lhs[i] != rhs[i])
        c++;
  }
  return c;
}
