//----------------------------------------------------------------------
// 16_factors.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static void printPrimeFactors(long long n) {
    long long factor = 2;

    while (factor * factor <= n) {
        while (n % factor == 0) {
            printf("%lld ", factor);
            n /= factor;
        }
        factor++;
    }

    if (n > 1) {
        printf("%lld", n);
    }

    printf("\n");
}

static int validateInput(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./factors <n>\n");
        return 0;
    }

    const long long n = atoll(argv[1]);
    if (n <= 1) {
        printf("Error: Input must be greater than 1.\n");
        return 0;
    }

    return 1;
}

int main(const int argc, const char *const argv[]) {
    if (!validateInput(argc, argv)) {
        return 1;
    }

    const long long n = atoll(argv[1]);
    printPrimeFactors(n);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 16_factors 16_factors.c
// ./16_factors 3757208
// 2 2 2 7 13 13 397

// ./16_factors 287994837222311
// 17 1739347 9739789
