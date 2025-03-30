//----------------------------------------------------------------------
// factors.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Main function: Accepts an integer n as a command-line argument.
// Writes the prime factors of n to standard output.
int main(int argc, char *argv[]) {
    // Check if an integer argument is passed
    if (argc < 2) {
        printf("Usage: ./factors <n>\n");
        return 1;
    }

    // Convert the command-line argument to a long integer
    long long n = atoll(argv[1]);

    if (n <= 1) {
        printf("Error: Input must be greater than 1.\n");
        return 1;
    }

    // Smallest prime factor
    long long factor = 2;

    // Find all prime factors smaller than the square root of n
    while (factor * factor <= n) {
        while (n % factor == 0) {
            printf("%lld ", factor);
            n /= factor;
        }
        factor++;
    }

    // If n is still greater than 1, it is a prime factor itself
    if (n > 1) {
        printf("%lld", n);
    }

    printf("\n");

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 16_factors 16_factors.c
// ./16_factors 3757208
// 2 2 2 7 13 13 397

// ./16_factors 287994837222311
// 17 1739347 9739789
