//----------------------------------------------------------------------
// quadratic.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function: Accepts floats b and c as command-line arguments.
// Computes the roots of the polynomial x^2 + bx + c using the quadratic formula.
// Writes the roots to standard output.
int main(int argc, char *argv[]) {
    // Check if two float arguments are passed
    if (argc < 3) {
        printf("Usage: ./quadratic <b> <c>\n");
        return 1;
    }

    // Convert command-line arguments from strings to floats
    double b = atof(argv[1]);
    double c = atof(argv[2]);

    double discriminant = b * b - 4.0 * c;

    if (discriminant < 0) {
        printf("Error: Math domain error - Negative discriminant.\n");
        return 1;
    }

    double d = sqrt(discriminant);

    double root1 = (-b + d) / 2.0;
    double root2 = (-b - d) / 2.0;

    printf("%lf\n", root1);
    printf("%lf\n", root2);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 06_quadratic 06_quadratic.c -lm
// ./06_quadratic -3.0 2.0
// 2.000000
// 1.000000

// ./quadratic 1.0 1.0
// Error: Math domain error - Negative discriminant.
