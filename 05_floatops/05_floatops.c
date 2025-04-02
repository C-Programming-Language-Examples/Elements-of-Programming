//----------------------------------------------------------------------
// 05_floatops.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void printArithmeticResults(const double a, const double b) {
    printf("%f + %f = %f\n", a, b, a + b);
    printf("%f - %f = %f\n", a, b, a - b);
    printf("%f * %f = %f\n", a, b, a * b);
    printf("%f / %f = %f\n", a, b, a / b);
}

static void printExponentResult(const double a, const double b) {
    const double exp = pow(a, b);
    printf("%f ** %f = %e\n", a, b, exp);  // Scientific notation for large numbers
}

int main(const int argc, const char *const argv[]) {
    if (argc < 3) {
        printf("Usage: ./floatops <a> <b>\n");
        return 1;
    }

    const double a = atof(argv[1]);
    const double b = atof(argv[2]);

    printArithmeticResults(a, b);
    printExponentResult(a, b);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 05_floatops 05_floatops.c -lm   // -lm links the math library for pow()
// ./05_floatops 123.456 78.9
// 123.456 +  78.9 = 202.356000
// 123.456 -  78.9 = 44.556000
// 123.456 *  78.9 = 9740.678400
// 123.456 /  78.9 = 1.564715
// 123.456 ** 78.9 = 1.047883e+165
