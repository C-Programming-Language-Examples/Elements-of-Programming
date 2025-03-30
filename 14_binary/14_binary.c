//----------------------------------------------------------------------
// binary.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Main function: Accepts an integer n as a command-line argument.
// Writes the binary representation of n to standard output.
// Limitation: Does not handle negative integers.
int main(int argc, char *argv[]) {
    // Check if an integer argument is passed
    if (argc < 2) {
        printf("Usage: ./binary <n>\n");
        return 1;
    }

    // Convert the command-line argument to an integer
    int n = atoi(argv[1]);

    // Handle non-positive integers
    if (n < 0) {
        printf("Error: Negative integers not supported.\n");
        return 1;
    }

    // Compute v as the largest power of 2 <= n.
    int v = 1;
    while (v <= n / 2) {
        v *= 2;
    }

    // Cast out powers of 2 in decreasing order.
    while (v > 0) {
        if (n < v) {
            printf("0");
        } else {
            printf("1");
            n -= v;
        }
        v /= 2;
    }

    // Print a newline at the end.
    printf("\n");

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o binary binary.c
// ./binary 19
// 10011

// ./binary 255
// 11111111

// ./binary 512
// 1000000000

// ./binary 1000000000
// 111011100110101100101000000000
