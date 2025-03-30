//----------------------------------------------------------------------
// twentyquestions.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random integer. Repeatedly read user guesses from
// standard input. Write 'Too low' or 'Too high' to standard output,
// as appropriate, in response to each guess. Write 'You win!' to
// standard output and exit when the user's guess is correct.

#define RANGE 1000000

int main(void) {
    int secret, guess = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer between 1 and RANGE
    secret = rand() % RANGE + 1;

    printf("I am thinking of a secret number between 1 and %d\n", RANGE);

    while (guess != secret) {
        printf("What is your guess? ");
        scanf("%d", &guess);

        if (guess < secret) {
            printf("Too low\n");
        } else if (guess > secret) {
            printf("Too high\n");
        } else {
            printf("You win!\n");
        }
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 22_twentyquestions 22_twentyquestions.c
// ./22_twentyquestions
// I am thinking of a secret number between 1 and 1000000
// What is your guess? 500000
// Too low
// What is your guess? 750000
// Too high
// ...
// What is your guess? 501686
// You win!
