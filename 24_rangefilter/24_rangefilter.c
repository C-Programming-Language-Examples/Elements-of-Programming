//----------------------------------------------------------------------
// rangefilter.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Accept integer command-line arguments lo and hi followed by a list of numbers.
// Write to standard output each of those integers that is in the range lo to hi, inclusive.

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./rangefilter <lo> <hi> <numbers...>\n");
        return 1;
    }

    int lo = atoi(argv[1]);
    int hi = atoi(argv[2]);

    for (int i = 3; i < argc; i++) {
        int value = atoi(argv[i]);
        if (value >= lo && value <= hi) {
            printf("%d ", value);
        }
    }
    printf("\n");

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 24_rangefilter 24_rangefilter.c
// ./24_rangefilter 1 9 3 5 12 8 0 7 11 9 15
// 3 5 8 7 9
