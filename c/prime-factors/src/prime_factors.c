#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  int c = 0;
  while((n % 2 == 0) && (c < MAXFACTORS)) {
    factors[c++] = 2;
    n /= 2;
  }

  for(uint64_t i=3; (i<=sqrt(n)) && (c < MAXFACTORS); i+=2) {
    while(n % i == 0) {
      factors[c++] = i;
      n /= i;
    }
  }

  if(n > 2)
    factors[c++] = n;
  
  return c;
}
