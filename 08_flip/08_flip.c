//----------------------------------------------------------------------
// flip.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number (0 or 1) and print the result
    if (rand() % 2 == 0) {
        printf("Heads\n");
    } else {
        printf("Tails\n");
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o flip flip.c
// ./flip
// Heads

// ./flip
// Tails

// ./flip
// Heads

// ./flip
// Heads

// ./flip
// Heads
