#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "RSA_functions.h"
#define BUF_LEN 1024
#define MSG 14

int main(int argc, char* argv[])
{
    char primes[BUF_LEN];
    int c;
    long long p1, p2;
    while ((c = getopt (argc, argv, "hgi:")) != -1)
        {
        switch (c)
            {
            case 'h':
                printf(" -i is for your own prime numbers, it should be followed by two numbers separated by '/', example: 13/47; \n -g is for generating prime numbers by the programm, it shouldn't be followed by anything; \n");
                return 0;
            case 'g':
                //generatePrimes(&p1, &p2);
                break;
            case 'i':
                strcpy(primes, optarg);
                break;
            case '?':
                fprintf(stderr, "Error: unknown parameter!\n");
                exit(-1);
            }
        }
    
        printf("Insert 2 prime numbers:\n");
        if (scanf("%lld %lld", &p1, &p2) != 2)
        {
            fprintf(stderr, "Error: incorrect input arguments\n");
            exit(-1);
        }
        long long n = p1 * p2;

        printf("n is : %lld\n", n);
        long long phi = (p1 - 1) * (p2 - 1);
        printf("phi is : %lld\n", phi);

        printf("Insert co-prime for %lld number less than %lld\n", phi, n);
        long long e;
        scanf("%lld", &e);
            
        long long d, x = 0, y = 0;
        auto [new_x, new_y, g] = xGCD (e, phi, x, y);
        
        if (g != 1)
        {
            printf("no solution\n");
            return 0;
        }
    
        else
        {
            new_x = (new_x % phi + phi) % phi;
            d = new_x;
            printf("oposite for e: %lld in ring phi: %lld is: %lld\n", e, phi, d);
        }
        
        int msg = MSG;
        printf("msg %d\n", msg);
        printf("msg^e %lld\n", modexp(msg, e, n));

        int64_t enc = modexp(msg, e, n);
        printf("Encrypted is %lld\n", enc);

        int64_t dec = modexp(enc, d, n);

        printf("Decrypted is %lld\n", dec);
        return 0;
}
