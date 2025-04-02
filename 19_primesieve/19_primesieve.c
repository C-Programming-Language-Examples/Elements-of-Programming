//----------------------------------------------------------------------
// 19_primesieve.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Uses the Sieve of Eratosthenes to find prime numbers up to n
int sieveOfEratosthenes(int n) {
    bool *isPrime = (bool *)malloc((n + 1) * sizeof(bool));
    int count = 0;

    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    free(isPrime);
    return count;
}

int validateInput(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./primesieve <n>\n");
        return -1;
    }

    int n = atoi(argv[1]);
    if (n < 2) {
        printf("Error: n must be greater than or equal to 2.\n");
        return -1;
    }

    return n;
}

int main(int argc, char *argv[]) {
    int n = validateInput(argc, argv);
    if (n == -1) {
        return 1;
    }

    int count = sieveOfEratosthenes(n);
    printf("%d\n", count);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 19_primesieve 19_primesieve.c
// ./19_primesieve 25
// 9

// ./19_primesieve 100
// 25

// ./19_primesieve 10000
// 1229

// ./19_primesieve 1000000
// 78498

// ./19_primesieve 100000000
// 5761455
