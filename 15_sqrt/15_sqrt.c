//----------------------------------------------------------------------
// sqrt.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the precision for Newton's method
#define EPSILON 1e-15

// Main function: Accepts a float c as a command-line argument.
// Writes the square root of c to 15 decimal places using Newton's method.
int main(int argc, char *argv[]) {
    // Check if a float argument is passed
    if (argc < 2) {
        printf("Usage: ./sqrt <c>\n");
        return 1;
    }

    // Convert the command-line argument to a double
    double c = atof(argv[1]);
    double t = c;

    // Newton's method for square root approximation
    while (fabs(t - c / t) > (EPSILON * t)) {
        t = (c / t + t) / 2.0;
    }

    // Print the result with 15 decimal places
    printf("%.15lf\n", t);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 15_sqrt 15_sqrt.c -lm
// ./15_sqrt 2.0
// 1.414213562373095

// ./15_sqrt 2544545
// 1595.163001075438
