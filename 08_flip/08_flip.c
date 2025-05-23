//----------------------------------------------------------------------
// 08_flip.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    if (rand() % 2 == 0) {
        printf("Heads\n");
    } else {
        printf("Tails\n");
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 08_flip 08_flip.c
// ./08_flip
// Heads

// ./08_flip
// Tails

// ./08_flip
// Heads

// ./08_flip
// Heads

// ./08_flip
// Heads
