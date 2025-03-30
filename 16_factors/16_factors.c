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

    // Check for non-positive numbers
    if (n <= 1) {
        printf("Error: Input must be greater than 1.\n");
        return 1;
    }

    // Start with the smallest prime factor
    long long factor = 2;

    // Find prime factors up to the square root of n
    while (factor * factor <= n) {
        while (n % factor == 0) {
            // Cast out and write factor
            printf("%lld ", factor);
            n /= factor;
        }
        factor++;
    }

    // If n is still greater than 1, it is a prime factor itself
    if (n > 1) {
        printf("%lld", n);
    }

    // Print a newline at the end
    printf("\n");

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o factors factors.c
// ./factors 3757208
// 2 2 2 7 13 13 397

// ./factors 287994837222311
// 17 1739347 9739789
