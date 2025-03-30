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

    int n = atoi(argv[1]);
    double total = 0.0;

    for (int i = 1; i <= n; i++) {
        total += 1.0 / i;
    }

    printf("%lf\n", total);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 12_harmonic 12_harmonic.c
// ./12_harmonic 2
// 1.500000

// ./12_harmonic 10
// 2.928968

// ./12_harmonic 10000
// 9.787606
