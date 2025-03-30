//----------------------------------------------------------------------
// sample.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function: Accepts integers m and n as command-line arguments.
// Writes to standard output a random sample of m integers from the range 0 to n-1 (no duplicates).
int main(int argc, char *argv[]) {
    // Check if two integer arguments are passed
    if (argc < 3) {
        printf("Usage: ./sample <m> <n>\n");
        return 1;
    }

    int m = atoi(argv[1]);  // Choose this many elements
    int n = atoi(argv[2]);  // From 0, 1, ..., n-1

    if (m > n) {
        printf("Error: m must be less than or equal to n.\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the permutation array
    int perm[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    // Create a random sample in perm[0], perm[1], ..., perm[m-1]
    for (int i = 0; i < m; i++) {
        // Choose a random integer r between i and n-1
        int r = i + rand() % (n - i);

        int temp = perm[r];
        perm[r] = perm[i];
        perm[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 17_sample 17_sample.c
// ./17_sample 6 16
// 9 6 3 5 4 13

// ./17_sample 10 1000
// 566 240 662 680 500 491 309 348 563 34

// ./17_sample 20 20
// 15 6 19 5 1 4 10 16 7 3 13 14 12 2 9 0 18 8 17 11
