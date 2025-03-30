#include <stdio.h>
#include <stdlib.h>

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
    double **probs = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        probs[i] = (double *)malloc(n * sizeof(double));
    }

    // Read the transition matrix from file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%lf", &probs[i][j]);
        }
    }
    fclose(file);

    // Initialize page ranks
    double *ranks = (double *)calloc(n, sizeof(double));
    ranks[0] = 1.0;

    // Power method to compute page ranks
    for (int move = 0; move < moves; move++) {
        double *newRanks = (double *)calloc(n, sizeof(double));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                newRanks[j] += ranks[k] * probs[k][j];
            }
        }
        free(ranks); // Free old ranks memory
        ranks = newRanks;
    }

    // Print the page ranks
    for (int i = 0; i < n; i++) {
        printf("%8.5f ", ranks[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(probs[i]);
    }
    free(probs);
    free(ranks);

    return 0;
}
