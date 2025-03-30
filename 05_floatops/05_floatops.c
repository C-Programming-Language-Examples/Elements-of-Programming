//----------------------------------------------------------------------
// floatops.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function: Accepts two float command-line arguments a and b.
// Uses them to illustrate float operators. Prints the results.
int main(int argc, char *argv[]) {
    // Check if two float arguments are passed
    if (argc < 3) {
        printf("Usage: ./floatops <a> <b>\n");
        return 1;
    }

    // Convert command-line arguments from strings to floats
    double a = atof(argv[1]);
    double b = atof(argv[2]);

    // Perform basic arithmetic operations
    double total = a + b;
    double diff = a - b;
    double prod = a * b;
    double quot = a / b;

    // Calculate exponent using the pow function from math.h
    double exp = pow(a, b);

    // Print the results in the specified format
    printf("%f +  %f = %f\n", a, b, total);
    printf("%f -  %f = %f\n", a, b, diff);
    printf("%f *  %f = %f\n", a, b, prod);
    printf("%f /  %f = %f\n", a, b, quot);
    printf("%f ** %f = %e\n", a, b, exp);  // Scientific notation for large numbers

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o floatops floatops.c -lm   // -lm links the math library for pow()
// ./floatops 123.456 78.9
// 123.456 +  78.9 = 202.356000
// 123.456 -  78.9 = 44.556000
// 123.456 *  78.9 = 9740.678400
// 123.456 /  78.9 = 1.564715
// 123.456 ** 78.9 = 1.047883e+165
