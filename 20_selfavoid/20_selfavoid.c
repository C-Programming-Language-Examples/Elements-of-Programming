//----------------------------------------------------------------------
// 20_selfavoid.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool **allocate2DBoolArray(int n) {
    bool **array = (bool **)malloc(n * sizeof(bool *));
    for (int i = 0; i < n; i++) {
        array[i] = (bool *)calloc(n, sizeof(bool));
    }
    return array;
}

void free2DBoolArray(bool **array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}

bool isDeadEnd(bool **a, int x, int y) {
    return a[x-1][y] && a[x+1][y] && a[x][y-1] && a[x][y+1];
}

// Performs a single self-avoiding walk in the n-by-n lattice
bool performWalk(int n) {
    bool **a = allocate2DBoolArray(n);
    int x = n / 2;
    int y = n / 2;

    while (x > 0 && x < n - 1 && y > 0 && y < n - 1) {
        a[x][y] = true;

        if (isDeadEnd(a, x, y)) {
            free2DBoolArray(a, n);
            return true;  // Dead end encountered
        }

        int r = rand() % 4;
        if (r == 0 && !a[x+1][y]) x += 1;
        else if (r == 1 && !a[x-1][y]) x -= 1;
        else if (r == 2 && !a[x][y+1]) y += 1;
        else if (r == 3 && !a[x][y-1]) y -= 1;
    }

    free2DBoolArray(a, n);
    return false;  // Walk completed successfully
}

// Runs multiple trials and calculates the percentage of dead ends
int runTrials(int n, int trials) {
    int deadEnds = 0;
    for (int t = 0; t < trials; t++) {
        if (performWalk(n)) {
            deadEnds++;
        }
    }
    return (100 * deadEnds) / trials;
}

bool validateInput(int argc, char *argv[], int *n, int *trials) {
    if (argc < 3) {
        printf("Usage: ./selfavoid <n> <trialCount>\n");
        return false;
    }

    *n = atoi(argv[1]);
    *trials = atoi(argv[2]);

    if (*n <= 1 || *trials <= 0) {
        printf("Error: n must be greater than 1 and trialCount must be positive.\n");
        return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    int n, trials;

    if (!validateInput(argc, argv, &n, &trials)) {
        return 1;
    }

    srand(time(NULL));

    int deadEndPercentage = runTrials(n, trials);
    printf("%d%% dead ends\n", deadEndPercentage);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 20_selfavoid 20_selfavoid.c
// ./20_selfavoid 5 100
// 0% dead ends

// ./20_selfavoid 20 100
// 27% dead ends

// ./20_selfavoid 40 100
// 80% dead ends

// ./20_selfavoid 80 100
// 96% dead ends

// ./20_selfavoid 5 1000
// 0% dead ends

// ./20_selfavoid 20 1000
// 33% dead ends

// ./20_selfavoid 40 1000
// 77% dead ends

// ./20_selfavoid 80 1000
// 98% dead ends
