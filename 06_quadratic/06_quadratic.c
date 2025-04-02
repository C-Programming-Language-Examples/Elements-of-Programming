//----------------------------------------------------------------------
// 06_quadratic.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculateDiscriminant(double b, double c) {
    return b * b - 4.0 * c;
}

void calculateRoots(double b, double d, double *root1, double *root2) {
    *root1 = (-b + d) / 2.0;
    *root2 = (-b - d) / 2.0;
}

void printRoots(double root1, double root2) {
    printf("%lf\n", root1);
    printf("%lf\n", root2);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./quadratic <b> <c>\n");
        return 1;
    }

    double b = atof(argv[1]);
    double c = atof(argv[2]);

    double discriminant = calculateDiscriminant(b, c);

    if (discriminant < 0) {
        printf("Error: Math domain error - Negative discriminant.\n");
        return 1;
    }

    double d = sqrt(discriminant);
    double root1, root2;
    calculateRoots(b, d, &root1, &root2);

    printRoots(root1, root2);

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
