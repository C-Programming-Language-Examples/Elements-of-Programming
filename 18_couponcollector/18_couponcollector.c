//----------------------------------------------------------------------
// couponcollector.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Accept integer n as a command-line argument. Write to standard
// output the number of coupons collected before obtaining one of
// each of n types.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./couponcollector <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);

    int count = 0;
    int collectedCount = 0;
    bool *isCollected = (bool *)calloc(n, sizeof(bool));

    srand(time(NULL));

    while (collectedCount < n) {
        int value = rand() % n;
        count++;
        if (!isCollected[value]) {
            collectedCount++;
            isCollected[value] = true;
        }
    }

    printf("%d\n", count);
    free(isCollected);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o couponcollector couponcollector.c
// ./couponcollector 1000
// 8507

// ./couponcollector 1000
