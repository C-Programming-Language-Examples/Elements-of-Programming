//----------------------------------------------------------------------
// 09_tenhellos.c
//----------------------------------------------------------------------

#include <stdio.h>

int main(void) {
    printf("1st Hello\n");
    printf("2nd Hello\n");
    printf("3rd Hello\n");
    for (int i = 4; i <= 10; i++) {
        printf("%dth Hello\n", i);
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 09_tenhellos 09_tenhellos.c
// ./09_tenhellos
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
