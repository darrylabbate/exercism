#include "collatz_conjecture.h"

static int collatz(int step, int n)
{
  if (n == 1) return step;
  return collatz(step + 1, (n & 1) ? n * 3 + 1 : n / 2);
}

int steps(int start)
{
  return (start <= 0) ? ERROR_VALUE : collatz(0, start);
}
