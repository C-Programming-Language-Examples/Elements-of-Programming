//----------------------------------------------------------------------
// intops.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function: Accepts int command-line arguments a and b.
// Uses them to illustrate integer operations. Prints the results.
int main(int argc, char *argv[]) {
    // Check if two integer arguments are passed
    if (argc < 3) {
        printf("Usage: ./intops <a> <b>\n");
        return 1;
    }

    // Convert command-line arguments from strings to integers
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // Perform basic arithmetic operations
    int total = a + b;
    int diff = a - b;
    int prod = a * b;

    // Perform integer division and modulus
    int quot = a / b;  // In C, / does integer division when both operands are int
    int rem = a % b;

    // Calculate exponent using the pow function from math.h
    long long exp = pow(a, b);  // Returns a double, cast to long long for integer result

    // Print the results in the specified format
    printf("%d +  %d = %d\n", a, b, total);
    printf("%d -  %d = %d\n", a, b, diff);
    printf("%d *  %d = %d\n", a, b, prod);
    printf("%d // %d = %d\n", a, b, quot);  // In C, // is represented by /
    printf("%d %%  %d = %d\n", a, b, rem);  // %% to print a literal % character
    printf("%d ** %d = %lld\n", a, b, exp);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 04_intops 04_intops.c -lm   // -lm links the math library for pow()
// ./04_intops 1234 5
// 1234 +  5 = 1239
// 1234 -  5 = 1229
// 1234 *  5 = 6170
// 1234 // 5 = 246
// 1234 %  5 = 4
// 1234 ** 5 = 2861381721051424
