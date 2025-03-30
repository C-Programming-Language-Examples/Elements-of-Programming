//----------------------------------------------------------------------
// average.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Read floats from the command-line arguments.
// Write to standard output the average of those floats.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./average <numbers>\n");
        return 1;
    }

    double total = 0.0;
    int count = 0;

    // Loop through command-line arguments
    for (int i = 1; i < argc; i++) {
        double value = atof(argv[i]);
        total += value;
        count++;
    }

    // Calculate and print the average
    if (count > 0) {
        double avg = total / count;
        printf("Average is %lf\n", avg);
    } else {
        printf("No numbers provided.\n");
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o average average.c
// ./average 10.0 5.0 6.0 3.0 7.0 32.0
// Average is 10.500000
