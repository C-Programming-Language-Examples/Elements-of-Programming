//----------------------------------------------------------------------
// 24_rangefilter.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static int isInRange(const int value, const int lo, const int hi) {
    return (value >= lo && value <= hi);
}

static void printFilteredNumbers(const int lo, const int hi, const int argc, const char *const argv[]) {
    for (int i = 3; i < argc; i++) {
        const int value = atoi(argv[i]);
        if (isInRange(value, lo, hi)) {
            printf("%d ", value);
        }
    }
    printf("\n");
}

static int validateInput(const int argc) {
    if (argc < 4) {
        printf("Usage: ./rangefilter <lo> <hi> <numbers...>\n");
        return 0;
    }
    return 1;
}

int main(const int argc, const char *const argv[]) {
    if (!validateInput(argc)) {
        return 1;
    }

    const int lo = atoi(argv[1]);
    const int hi = atoi(argv[2]);

    printFilteredNumbers(lo, hi, argc, argv);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 24_rangefilter 24_rangefilter.c
// ./24_rangefilter 1 9 3 5 12 8 0 7 11 9 15
// 3 5 8 7 9
