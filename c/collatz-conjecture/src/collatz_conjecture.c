#include "collatz_conjecture.h"

int steps(int start)
{
  return (start <= 0) ? ERROR_VALUE : collatz(0, start);
}

int collatz(int step, int n)
{
  if (n == 1) return step;
  return (n & 1) ? collatz(step+1, n*3+1) : collatz(step+1, n/2);
}
