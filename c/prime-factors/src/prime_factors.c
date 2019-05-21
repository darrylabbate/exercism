#include "prime_factors.h"
#include <math.h>

static size_t iter(int c, int i, uint64_t n, uint64_t factors[static MAXFACTORS])
{
  if ((n % i) == 0) {
    factors[c] = i;
    return iter(c + 1, i, n / i, factors);
  } else if (i <= sqrt(n)) {
    return iter(c, i == 2 ? 3 : i + 2, n, factors);
  }

  if (n > 2)
    factors[c++] = n;
  return c;
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  return n <= 1 ? 0 : iter(0, 2, n, factors);
}
