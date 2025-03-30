//----------------------------------------------------------------------
// primesieve.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Accept integer n as a command-line argument. Write to standard
// output the number of primes <= n.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./primesieve <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int count = 0;

    bool *isPrime = (bool *)malloc((n + 1) * sizeof(bool));

    // Initially assume all integers are prime.
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    // Sieve of Eratosthenes.
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count primes.
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    printf("%d\n", count);
    free(isPrime);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o primesieve primesieve.c
// ./primesieve 25
// 9

// ./primesieve 100
// 25

// ./primesieve 10000
// 1229

// ./primesieve 1000000
// 78498

// ./primesieve 100000000
// 5761455
