#include "grains.h"

#define TOTALSQUARES 64

uint64_t square(int x)
{
  return (!x) || (x > TOTALSQUARES) ? 0 : (uint64_t) 1 << (x - 1);
}

static uint64_t calc_total(uint64_t t, int i)
{
  return i > TOTALSQUARES ? t : calc_total(t + square(i), i + 1);
}

uint64_t total(void)
{
  return calc_total(0, 0);
}
