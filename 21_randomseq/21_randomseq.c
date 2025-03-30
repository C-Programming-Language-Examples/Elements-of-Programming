//----------------------------------------------------------------------
// randomseq.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Accept integer command-line argument n. Write to standard output
// a random sequence of n floats in the range [0, 1).

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./randomseq <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        double rand_float = (double)rand() / (double)RAND_MAX;
        printf("%f\n", rand_float);
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 21_randomseq 21_randomseq.c
// ./21_randomseq 10
// 0.304702
// 0.231551
// 0.473591
// 0.486577
// 0.498223
// 0.161394
// 0.562148
// 0.685202
// 0.983308
// 0.746265
