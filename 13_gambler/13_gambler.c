//----------------------------------------------------------------------
// gambler.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function: Simulates a gambling scenario based on the given arguments.
// Accepts integer command-line arguments stake, goal, and trials.
int main(int argc, char *argv[]) {
    // Check if three integer arguments are passed
    if (argc < 4) {
        printf("Usage: ./gambler <stake> <goal> <trials>\n");
        return 1;
    }

    // Convert the command-line arguments to integers
    int stake = atoi(argv[1]);
    int goal = atoi(argv[2]);
    int trials = atoi(argv[3]);

    int bets = 0;
    int wins = 0;

    // Seed the random number generator
    srand(time(NULL));

    for (int t = 0; t < trials; t++) {
        int cash = stake;
        // Run one experiment until cash reaches 0 or goal
        while (cash > 0 && cash < goal) {
            // Simulate one bet
            bets++;
            if (rand() % 2 == 0) {  // 50% chance for Heads or Tails
                cash++;  // Win the bet
            } else {
                cash--;  // Lose the bet
            }
        }

        if (cash == goal) {
            wins++;
        }
    }

    int winPercentage = (100 * wins) / trials;
    int avgBets = bets / trials;

    printf("%d%% wins\n", winPercentage);
    printf("Avg # bets: %d\n", avgBets);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 13_gambler 13_gambler.c
// ./13_gambler 10 20 1000
// 49% wins
// Avg # bets: 99

// ./13_gambler 50 250 100
// 21% wins
// Avg # bets: 12712

// ./13_gambler 500 2500 100
// 21% wins
// Avg # bets: 1002424
