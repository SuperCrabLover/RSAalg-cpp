#include <stdio.h>
#include <stdlib.h>
#include "RSA_functions.h"

int main(void) {
    long long p1 = 0, p2 = 0;
    printf("Insert 2 prime numbers:\n");
    if (scanf("%lld %lld", &p1, &p2) != 2) {
        fprintf(stderr, "Error: incorrect input arguments\n");
        exit(-1);
    }
	long long n = p1 * p2;

	printf("n is : %lld\n", n);
	long long phi = (p1-1)*(p2-1);
	printf("phi is : %lld\n", phi);

	printf("Insert co-prime for %lld number less than %lld\n", phi, n); 
	long long e;
	scanf("%lld", &e);
	
	long long d, x, y;
	long long g = xGCD (e, phi, x, y);
    
    if (g != 1) {
        printf("no solution\n");
        return 0;
    }
	else {
		x = (x % phi + phi) % phi;
		d = x;
		printf("oposite for e: %lld in ring phi: %lld is: %lld\n", e, phi, d);
	}
    
	int msg = MSG;
	printf("msg %d\n", msg);
	printf("msg^e %lld\n", modexp(msg, e, n));

	long long enc = modexp(msg, e, n);
	printf("Encrypted is %lld\n", enc);

	long long dec = modexp(enc, d, n);

	printf("Decrypted is %lld\n", dec);
	return 0;
}
