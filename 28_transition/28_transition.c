//----------------------------------------------------------------------
// 28_transition.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "tiny.txt"

static double** readTransitionMatrix(const char* const filename, int* const n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n);
    int discard;
    fscanf(file, "%d", &discard); // Discard the second int from input

    double **p = (double **)malloc(*n * sizeof(double *));
    for (int i = 0; i < *n; i++) {
        p[i] = (double *)malloc(*n * sizeof(double));
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%lf", &p[i][j]);
        }
    }

    fclose(file);
    return p;
}

static void freeTransitionMatrix(double **const p, const int n) {
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
}

static void runMarkovChain(double **const p, const int n, const int moves, int *const hits) {
    int page = 0;
    srand(time(NULL));

    for (int i = 0; i < moves; i++) {
        const double r = (double)rand() / RAND_MAX;
        double total = 0.0;
        for (int j = 0; j < n; j++) {
            total += p[page][j];
            if (r < total) {
                page = j;
                break;
            }
        }
        hits[page]++;
    }
}

static void printFrequencies(const int *const hits, const int n, const int moves) {
    for (int i = 0; i < n; i++) {
        printf("%8.5f ", (double)hits[i] / moves);
    }
    printf("\n");
}

int main(const int argc, const char *const argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <moves>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const int moves = atoi(argv[1]);
    int n;

    double **p = readTransitionMatrix(FILENAME, &n);
    int *hits = (int *)calloc(n, sizeof(int));

    runMarkovChain(p, n, moves, hits);
    printFrequencies(hits, n, moves);

    freeTransitionMatrix(p, n);
    free(hits);

    return EXIT_SUCCESS;
}

// Compile and run:
// gcc -o 28_randomsurfer 28_randomsurfer.c -lm
// ./28_randomsurfer 10000
