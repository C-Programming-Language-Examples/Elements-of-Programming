//----------------------------------------------------------------------
// 29_transition.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "tiny.txt"

static double** readTransitionMatrix(const char* const filename, int* const n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n);
    int discard;
    fscanf(file, "%d", &discard);  // Discard the second integer

    double **probs = (double **)malloc(*n * sizeof(double *));
    for (int i = 0; i < *n; i++) {
        probs[i] = (double *)malloc(*n * sizeof(double));
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%lf", &probs[i][j]);
        }
    }
    fclose(file);
    return probs;
}

static void freeTransitionMatrix(double **const probs, const int n) {
    for (int i = 0; i < n; i++) {
        free(probs[i]);
    }
    free(probs);
}

static double* computePageRanks(double **const probs, const int n, const int moves) {
    double *ranks = (double *)calloc(n, sizeof(double));
    ranks[0] = 1.0;

    for (int move = 0; move < moves; move++) {
        double *newRanks = (double *)calloc(n, sizeof(double));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                newRanks[j] += ranks[k] * probs[k][j];
            }
        }
        free(ranks);
        ranks = newRanks;
    }
    return ranks;
}

static void printPageRanks(const double *const ranks, const int n) {
    for (int i = 0; i < n; i++) {
        printf("%8.5f ", ranks[i]);
    }
    printf("\n");
}

static int validateInput(const int argc, const char *const argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <moves>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return atoi(argv[1]);
}

int main(const int argc, const char *const argv[]) {
    const int moves = validateInput(argc, argv);
    int n;

    double **probs = readTransitionMatrix(FILENAME, &n);
    double *ranks = computePageRanks(probs, n, moves);
    printPageRanks(ranks, n);

    free(ranks);
    freeTransitionMatrix(probs, n);

    return 0;
}

// Compile and run:
// gcc -o 29_markov 29_markov.c -lm
// ./29_markov 20
