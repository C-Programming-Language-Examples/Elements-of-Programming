//----------------------------------------------------------------------
// 14_binary.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Computes the largest power of 2 less than or equal to n
static int largestPowerOfTwo(const int n) {
    int v = 1;
    while (v <= n / 2) {
        v *= 2;
    }
    return v;
}

static void printBinary(const int n) {
    int v = largestPowerOfTwo(n);
    while (v > 0) {
        printf("%d", (n >= v) ? 1 : 0);
        if (n >= v) n -= v;
        v /= 2;
    }
    printf("\n");
}

int main(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./binary <n>\n");
        return 1;
    }

    const int n = atoi(argv[1]);

    if (n < 0) {
        printf("Error: Negative integers not supported.\n");
        return 1;
    }

    printBinary(n);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 14_binary 14_binary.c
// ./14_binary 19
// 10011

// ./14_binary 255
// 11111111

// ./14_binary 512
// 1000000000

// ./14_binary 1000000000
// 111011100110101100101000000000
