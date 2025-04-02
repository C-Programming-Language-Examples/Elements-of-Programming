//----------------------------------------------------------------------
// 21_randomseq.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates a random float in the range [0, 1)
double generateRandomFloat() {
    return (double)rand() / (double)RAND_MAX;
}

void printRandomSequence(int n) {
    for (int i = 0; i < n; i++) {
        printf("%f\n", generateRandomFloat());
    }
}

int validateInput(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./randomseq <n>\n");
        return -1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return -1;
    }

    return n;
}

int main(int argc, char *argv[]) {
    int n = validateInput(argc, argv);
    if (n == -1) {
        return 1;
    }

    srand(time(NULL));

    printRandomSequence(n);

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
