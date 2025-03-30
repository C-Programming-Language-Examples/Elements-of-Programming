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

    // Convert the command-line argument to an integer
    int n = atoi(argv[1]);

    // Initialize variables
    int power = 1;
    
    // Print the first n powers of two
    for (int i = 0; i <= n; i++) {
        // Print the current power of two
        printf("%d %d\n", i, power);
        // Calculate the next power of two
        power = 2 * power;
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o powersoftwo powersoftwo.c
// ./powersoftwo 0
// 0 1

// ./powersoftwo 1
// 0 1
// 1 2

// ./powersoftwo 2
// 0 1
// 1 2
// 2 4

// ./powersoftwo 3
// 0 1
// 1 2
// 2 4
// 3 8

// ./powersoftwo 4
// 0 1
// 1 2
// 2 4
// 3 8
// 4 16
