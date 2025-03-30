//----------------------------------------------------------------------
// harmonic.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Main function: Accepts an integer n as a command-line argument.
// Writes the value of the nth harmonic number to standard output.
int main(int argc, char *argv[]) {
    // Check if an integer argument is passed
    if (argc < 2) {
        printf("Usage: ./harmonic <n>\n");
        return 1;
    }

    // Convert the command-line argument to an integer
    int n = atoi(argv[1]);

    // Initialize the sum as a floating-point number
    double total = 0.0;

    // Calculate the nth harmonic number
    for (int i = 1; i <= n; i++) {
        // Add the ith term to the sum
        total += 1.0 / i;
    }

    // Print the result
    printf("%lf\n", total);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o harmonic harmonic.c
// ./harmonic 2
// 1.500000

// ./harmonic 10
// 2.928968

// ./harmonic 10000
// 9.787606
