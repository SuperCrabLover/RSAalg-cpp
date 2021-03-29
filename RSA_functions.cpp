#include "RSA_functions.h"

long long xGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
       x = 1;
       y = 0;
       return a;
    }
    long long x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long modexp(long long x, long long y, long long N) {
  if (y == 0)
      return 1;
  long long z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return (x*z*z) % N;
}
