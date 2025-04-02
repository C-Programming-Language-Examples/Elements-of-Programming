//----------------------------------------------------------------------
// 04_intops.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void printArithmeticResults(const int a, const int b) {
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d // %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);
}

static void printExponentResult(const int a, const int b) {
    const long long exp = pow(a, b);
    printf("%d ** %d = %lld\n", a, b, exp);
}

int main(const int argc, const char *const argv[]) {
    if (argc < 3) {
        printf("Usage: ./intops <a> <b>\n");
        return 1;
    }

    const int a = atoi(argv[1]);
    const int b = atoi(argv[2]);

    printArithmeticResults(a, b);
    printExponentResult(a, b);

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
