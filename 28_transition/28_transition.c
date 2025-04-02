//----------------------------------------------------------------------
// 28_transition.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "tiny.txt"

double** readTransitionMatrix(const char* filename, int* n) {
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

void freeTransitionMatrix(double **p, int n) {
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
}

void runMarkovChain(double **p, int n, int moves, int *hits) {
    int page = 0;
    srand(time(NULL));

    for (int i = 0; i < moves; i++) {
        double r = (double)rand() / RAND_MAX;
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

void printFrequencies(int *hits, int n, int moves) {
    for (int i = 0; i < n; i++) {
        printf("%8.5f ", (double)hits[i] / moves);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <moves>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int moves = atoi(argv[1]);
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
