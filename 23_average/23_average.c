//----------------------------------------------------------------------
// 23_average.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

double calculateAverage(double total, int count) {
    return (count > 0) ? total / count : 0.0;
}

void sumNumbers(int argc, char *argv[], double *total, int *count) {
    for (int i = 1; i < argc; i++) {
        double value = atof(argv[i]);
        *total += value;
        (*count)++;
    }
}

void printAverage(double avg, int count) {
    if (count > 0) {
        printf("Average is %lf\n", avg);
    } else {
        printf("No numbers provided.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./average <numbers>\n");
        return 1;
    }

    double total = 0.0;
    int count = 0;

    sumNumbers(argc, argv, &total, &count);
    double avg = calculateAverage(total, count);
    printAverage(avg, count);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 23_average 23_average.c
// ./23_average 10.0 5.0 6.0 3.0 7.0 32.0
// Average is 10.500000
