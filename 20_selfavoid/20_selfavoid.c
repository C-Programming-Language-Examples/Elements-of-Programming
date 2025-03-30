//----------------------------------------------------------------------
// selfavoid.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Accept integers n and trialCount as command-line arguments.
// Perform trialCount random self-avoiding walks in an n-by-n lattice.
// Write to standard output the percentage of dead ends encountered.

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./selfavoid <n> <trialCount>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int trials = atoi(argv[2]);
    int deadEnds = 0;

    srand(time(NULL));

    for (int t = 0; t < trials; t++) {
        // Create an n-by-n array, initialized to false
        bool **a = (bool **)malloc(n * sizeof(bool *));
        for (int i = 0; i < n; i++) {
            a[i] = (bool *)calloc(n, sizeof(bool));
        }

        int x = n / 2;
        int y = n / 2;

        while (x > 0 && x < n - 1 && y > 0 && y < n - 1) {
            a[x][y] = true;

            // Check for dead end
            if (a[x-1][y] && a[x+1][y] && a[x][y-1] && a[x][y+1]) {
                deadEnds++;
                break;
            }

            // Make a random move
            int r = rand() % 4;
            if (r == 0 && !a[x+1][y]) {
                x += 1;
            } else if (r == 1 && !a[x-1][y]) {
                x -= 1;
            } else if (r == 2 && !a[x][y+1]) {
                y += 1;
            } else if (r == 3 && !a[x][y-1]) {
                y -= 1;
            }
        }

        for (int i = 0; i < n; i++) {
            free(a[i]);
        }
        free(a);
    }

    printf("%d%% dead ends\n", 100 * deadEnds / trials);

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
