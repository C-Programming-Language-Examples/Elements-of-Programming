//----------------------------------------------------------------------
// 18_couponcollector.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Simulates the coupon collection process and returns the number of trials
int collectCoupons(int n) {
    int count = 0, collectedCount = 0;
    bool *isCollected = (bool *)calloc(n, sizeof(bool));

    while (collectedCount < n) {
        int value = rand() % n;
        count++;
        if (!isCollected[value]) {
            collectedCount++;
            isCollected[value] = true;
        }
    }

    free(isCollected);
    return count;
}

int validateInput(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./couponcollector <n>\n");
        return -1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return -1;
    }

    return n;
}

int main(int argc, char *argv[]) {
    int n = validateInput(argc, argv);
    if (n == -1) {
        return 1;
    }

    srand(time(NULL));

    int count = collectCoupons(n);
    printf("%d\n", count);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 18_couponcollector 18_couponcollector.c
// ./18_couponcollector 1000
// 8507
