//----------------------------------------------------------------------
// 13_gambler.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int simulateTrial(const int stake, const int goal, int *const bets) {
    int cash = stake;
    while (cash > 0 && cash < goal) {
        (*bets)++;
        cash += (rand() % 2 == 0) ? 1 : -1;
    }
    return cash == goal;
}

static void runSimulation(const int stake, const int goal, const int trials) {
    int bets = 0, wins = 0;

    srand(time(NULL));

    for (int t = 0; t < trials; t++) {
        if (simulateTrial(stake, goal, &bets)) {
            wins++;
        }
    }

    const int winPercentage = (100 * wins) / trials;
    const int avgBets = bets / trials;

    printf("%d%% wins\n", winPercentage);
    printf("Avg # bets: %d\n", avgBets);
}

int main(const int argc, const char *const argv[]) {
    if (argc < 4) {
        printf("Usage: ./gambler <stake> <goal> <trials>\n");
        return 1;
    }

    const int stake = atoi(argv[1]);
    const int goal = atoi(argv[2]);
    const int trials = atoi(argv[3]);

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
