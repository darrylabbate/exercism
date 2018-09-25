#include "perfect_numbers.h"

static int aliquot_sum(int n)
{
  if(n == 1)
    return 0;
  int r = 1;
  int i;
  for(i=2; i*i<n; i++)
    if((n % i) == 0)
      r += i + (n / i);
  return r + (i * i == n ? i : 0);
}

kind classify_number(int n)
{
  kind class = ERROR;
  if(n > 0) {
    int sum = aliquot_sum(n);
    if(sum > n)
      class = ABUNDANT_NUMBER;
    else if(sum < n)
      class = DEFICIENT_NUMBER;
    else
      class = PERFECT_NUMBER;
  }
  return class;
}
