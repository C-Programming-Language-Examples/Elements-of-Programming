//----------------------------------------------------------------------
// 15_sqrt.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-15

double newtonSqrt(double c) {
    double t = c;
    while (fabs(t - c / t) > (EPSILON * t)) {
        t = (c / t + t) / 2.0;
    }
    return t;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./sqrt <c>\n");
        return 1;
    }

    double c = atof(argv[1]);

    if (c < 0) {
        printf("Error: Square root of a negative number is not defined in real numbers.\n");
        return 1;
    }

    double result = newtonSqrt(c);
    printf("%.15lf\n", result);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 15_sqrt 15_sqrt.c -lm
// ./15_sqrt 2.0
// 1.414213562373095

// ./15_sqrt 2544545
// 1595.163001075438
