//----------------------------------------------------------------------
// divisorpattern.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Main function: Accepts an integer n as a command-line argument.
// Writes an n-by-n table with an asterisk if either i divides j or j divides i.
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./divisorpattern 5\n");
        return 1;
    }

    int n = atoi(argv[1]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i % j == 0) || (j % i == 0)) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("%d\n", i);
    }

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
