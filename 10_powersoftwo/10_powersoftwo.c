//----------------------------------------------------------------------
// 10_powersoftwo.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static int calculatePowerOfTwo(const int exponent) {
    return 1 << exponent;
}

static void printPowersOfTwo(const int n) {
    for (int i = 0; i <= n; i++) {
        printf("%d %d\n", i, calculatePowerOfTwo(i));
    }
}

int main(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./powersoftwo <n>\n");
        return 1;
    }

    const int n = atoi(argv[1]);
    printPowersOfTwo(n);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 10_powersoftwo 10_powersoftwo.c
// ./10_powersoftwo 0
// 0 1

// ./10_powersoftwo 1
// 0 1
// 1 2

// ./10_powersoftwo 2
// 0 1
// 1 2
// 2 4

// ./10_powersoftwo 3
// 0 1
// 1 2
// 2 4
// 3 8

// ./10_powersoftwo 4
// 0 1
// 1 2
// 2 4
// 3 8
// 4 16
