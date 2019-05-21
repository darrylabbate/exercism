#include "perfect_numbers.h"
#include <stdint.h>

static int aliquot_sum(int n, int i, uint64_t r)
{
  if (n == 1) return 0;

  return i * i < n ? aliquot_sum(n, i + 1, (n % i) == 0 ? r += i + (n / i) : r) : r;
}

kind classify_number(int n)
{
  if (n <= 0) return ERROR;

  return aliquot_sum(n, 2, 1) > n ? ABUNDANT_NUMBER : aliquot_sum(n, 2, 1) < n ? DEFICIENT_NUMBER : PERFECT_NUMBER;
}
