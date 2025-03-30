#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "tiny.txt"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <moves>\n", argv[0]);
        return 1;
    }

    int moves = atoi(argv[1]);

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", FILENAME);
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    int discard;
    fscanf(file, "%d", &discard); // Discard the second int from input

    // Allocate memory for the transition matrix
    double **p = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        p[i] = (double *)malloc(n * sizeof(double));
    }

    // Read the transition matrix from file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%lf", &p[i][j]);
        }
    }
    fclose(file);

    // Allocate and initialize the hits array
    int *hits = (int *)calloc(n, sizeof(int));
    int page = 0; // Start at page 0
    srand(time(NULL)); // Seed the random number generator

    // Perform the simulation
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

    // Print the page ranks
    for (int i = 0; i < n; i++) {
        printf("%8.5f ", (double)hits[i] / moves);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
    free(hits);

    return 0;
}
