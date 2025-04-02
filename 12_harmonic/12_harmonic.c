//----------------------------------------------------------------------
// 12_harmonic.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static double calculateHarmonicNumber(const int n) {
    double total = 0.0;
    for (int i = 1; i <= n; i++) {
        total += 1.0 / i;
    }
    return total;
}

static void printHarmonicNumber(const double result) {
    printf("%lf\n", result);
}

int main(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./harmonic <n>\n");
        return 1;
    }

    const int n = atoi(argv[1]);
    const double result = calculateHarmonicNumber(n);
    printHarmonicNumber(result);

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
