//----------------------------------------------------------------------
// 22_twentyquestions.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 1000000

int generateSecretNumber() {
    return rand() % RANGE + 1;
}

int getUserGuess() {
    int guess;
    printf("What is your guess? ");
    scanf("%d", &guess);
    return guess;
}

void giveFeedback(int guess, int secret) {
    if (guess < secret) {
        printf("Too low\n");
    } else if (guess > secret) {
        printf("Too high\n");
    } else {
        printf("You win!\n");
    }
}

void playGuessingGame(int secret) {
    int guess = 0;

    while (guess != secret) {
        guess = getUserGuess();
        giveFeedback(guess, secret);
    }
}

int main(void) {
    srand(time(NULL));

    int secret = generateSecretNumber();

    printf("I am thinking of a secret number between 1 and %d\n", RANGE);

    playGuessingGame(secret);

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
