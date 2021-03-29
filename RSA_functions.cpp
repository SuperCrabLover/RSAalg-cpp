#include "RSA_functions.h"

tuple<int64_t, int64_t, int64_t> xGCD(int64_t a, int64_t b, int64_t x, int64_t y) {
    tuple<int64_t, int64_t, int64_t> res;
    if (b == 0) {
        x = 1;
        y = 0;
        res = make_tuple(x,y,a);
    }
    else {
        auto [x1, y1, gcd] = xGCD(b, a % b, x, y);
        x = y1;
        y = x1 - (a / b) * y1;
        res = make_tuple(x,y,gcd);
    }
    return res;
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
