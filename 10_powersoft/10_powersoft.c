//----------------------------------------------------------------------
// powersoftwo.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Main function: Accepts a positive integer n as a command-line argument.
// Writes a table showing the first n powers of two.
int main(int argc, char *argv[]) {
    // Check if an integer argument is passed
    if (argc < 2) {
        printf("Usage: ./powersoftwo <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int power = 1;
    
    for (int i = 0; i <= n; i++) {
        printf("%d %d\n", i, power);
        power = 2 * power;
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 10_powersoftwo 10_powersoftwo.c
// ./10_powersoftwo 0
// 0 1

// ./10_powersoftwo 1
// 0 1
// 1 2

// ./10_powersoftwo 2
// 0 1
// 1 2
// 2 4

// ./10_powersoftwo 3
// 0 1
// 1 2
// 2 4
// 3 8

// ./10_powersoftwo 4
// 0 1
// 1 2
// 2 4
// 3 8
// 4 16
