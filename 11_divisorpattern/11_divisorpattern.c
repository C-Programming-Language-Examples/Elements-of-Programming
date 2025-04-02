//----------------------------------------------------------------------
// 11_divisorpattern.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static int isDivisor(const int a, const int b) {
    return (a % b == 0) || (b % a == 0);
}

static void printDivisorPattern(const int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%s ", isDivisor(i, j) ? "*" : " ");
        }
        printf("%d\n", i);
    }
}

int main(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./divisorpattern <n>\n");
        return 1;
    }

    const int n = atoi(argv[1]);
    printDivisorPattern(n);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 11_divisorpattern 11_divisorpattern.c
// ./11_divisorpattern 1
// * 1

// ./11_divisorpattern 2
// * * 1
// * * 2

// ./11_divisorpattern 3
// * * * 1
// * *   2
// *   * 3

// ./11_divisorpattern 4
// * * * * 1
// * *   * 2
// *   *   3
// * *   * 4

// ./11_divisorpattern 5
// * * * * * 1
// * *   *   2
// *   *     3
// * *   *   4
// *       * 5
