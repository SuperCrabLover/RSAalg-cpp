#include "RSA_functions.h"

tuple<int64_t, int64_t, int64_t> xGCD(int64_t a, int64_t b, int64_t x, int64_t y)
{
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

int64_t modexp (int64_t x, int64_t y, int64_t N)
{
    int64_t res = 1;
    while (y) {
        if (y & 1)
            res = (res * x) % N;
        x = (x * x) % N;
        y >>= 1;
    }
    return res;
}
