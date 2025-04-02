//----------------------------------------------------------------------
// 13_gambler.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int simulateTrial(int stake, int goal, int *bets) {
    int cash = stake;
    while (cash > 0 && cash < goal) {
        (*bets)++;
        cash += (rand() % 2 == 0) ? 1 : -1;
    }
    return cash == goal;
}

void runSimulation(int stake, int goal, int trials) {
    int bets = 0, wins = 0;

    srand(time(NULL));

    for (int t = 0; t < trials; t++) {
        if (simulateTrial(stake, goal, &bets)) {
            wins++;
        }
    }

    int winPercentage = (100 * wins) / trials;
    int avgBets = bets / trials;

    printf("%d%% wins\n", winPercentage);
    printf("Avg # bets: %d\n", avgBets);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: ./gambler <stake> <goal> <trials>\n");
        return 1;
    }

    int stake = atoi(argv[1]);
    int goal = atoi(argv[2]);
    int trials = atoi(argv[3]);

    runSimulation(stake, goal, trials);

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
