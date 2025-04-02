//----------------------------------------------------------------------
// 23_average.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static double calculateAverage(const double total, const int count) {
    return (count > 0) ? total / count : 0.0;
}

static void sumNumbers(const int argc, const char *const argv[], double *const total, int *const count) {
    for (int i = 1; i < argc; i++) {
        const double value = atof(argv[i]);
        *total += value;
        (*count)++;
    }
}

static void printAverage(const double avg, const int count) {
    if (count > 0) {
        printf("Average is %lf\n", avg);
    } else {
        printf("No numbers provided.\n");
    }
}

int main(const int argc, const char *const argv[]) {
    if (argc < 2) {
        printf("Usage: ./average <numbers>\n");
        return 1;
    }

    double total = 0.0;
    int count = 0;

    sumNumbers(argc, argv, &total, &count);
    const double avg = calculateAverage(total, count);
    printAverage(avg, count);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 23_average 23_average.c
// ./23_average 10.0 5.0 6.0 3.0 7.0 32.0
// Average is 10.500000
