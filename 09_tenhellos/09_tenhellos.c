//----------------------------------------------------------------------
// tenhellos.c
//----------------------------------------------------------------------

#include <stdio.h>

// Main function: Writes 10 Hellos to standard output.
int main(void) {
    // Print the first three Hellos with special suffixes
    printf("1st Hello\n");
    printf("2nd Hello\n");
    printf("3rd Hello\n");

    // Loop from 4 to 10 to print the remaining Hellos
    for (int i = 4; i <= 10; i++) {
        printf("%dth Hello\n", i);
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o tenhellos tenhellos.c
// ./tenhellos
// 1st Hello
// 2nd Hello
// 3rd Hello
// 4th Hello
// 5th Hello
// 6th Hello
// 7th Hello
// 8th Hello
// 9th Hello
// 10th Hello
