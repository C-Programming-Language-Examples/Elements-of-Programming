//----------------------------------------------------------------------
// 17_sample.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates a random sample of m integers from 0 to n-1 (no duplicates)
static void generateRandomSample(const int m, const int n) {
    int perm[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int r = i + rand() % (n - i);
        int temp = perm[r];
        perm[r] = perm[i];
        perm[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

static int validateInput(const int argc, const char *const argv[], int *const m, int *const n) {
    if (argc < 3) {
        printf("Usage: ./sample <m> <n>\n");
        return 0;
    }

    *m = atoi(argv[1]);
    *n = atoi(argv[2]);

    if (*m > *n) {
        printf("Error: m must be less than or equal to n.\n");
        return 0;
    }

    return 1;
}

int main(const int argc, const char *const argv[]) {
    int m, n;

    if (!validateInput(argc, argv, &m, &n)) {
        return 1;
    }

    srand(time(NULL));
    generateRandomSample(m, n);

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
