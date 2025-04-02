//----------------------------------------------------------------------
// 18_couponcollector.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Simulates the coupon collection process and returns the number of trials
static int collectCoupons(const int n) {
    int count = 0, collectedCount = 0;
    bool *const isCollected = (bool *)calloc(n, sizeof(bool));

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

static int validateInput(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./couponcollector <n>\n");
        return -1;
    }

    const int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return -1;
    }

    return n;
}

int main(const int argc, const char *const argv[]) {
    const int n = validateInput(argc, argv);
    if (n == -1) {
        return 1;
    }

    srand(time(NULL));

    const int count = collectCoupons(n);
    printf("%d\n", count);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 18_couponcollector 18_couponcollector.c
// ./18_couponcollector 1000
// 8507
