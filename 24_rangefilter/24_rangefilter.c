//----------------------------------------------------------------------
// 24_rangefilter.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int isInRange(int value, int lo, int hi) {
    return (value >= lo && value <= hi);
}

void printFilteredNumbers(int lo, int hi, int argc, char *argv[]) {
    for (int i = 3; i < argc; i++) {
        int value = atoi(argv[i]);
        if (isInRange(value, lo, hi)) {
            printf("%d ", value);
        }
    }
    printf("\n");
}

int validateInput(int argc) {
    if (argc < 4) {
        printf("Usage: ./rangefilter <lo> <hi> <numbers...>\n");
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (!validateInput(argc)) {
        return 1;
    }

    int lo = atoi(argv[1]);
    int hi = atoi(argv[2]);

    printFilteredNumbers(lo, hi, argc, argv);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 24_rangefilter 24_rangefilter.c
// ./24_rangefilter 1 9 3 5 12 8 0 7 11 9 15
// 3 5 8 7 9
