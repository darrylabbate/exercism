#include "collatz_conjecture.h"
#include <stdbool.h>

int steps(int start)
{
  int step = 0;
  int n = start;

  if (start <= 0)
    return ERROR_VALUE;

  while (n != 1) {
    step++;
    if (n % 2 == 0)
      n = n / 2;
    else
      n = n * 3 + 1;
  }
  return step;
}
