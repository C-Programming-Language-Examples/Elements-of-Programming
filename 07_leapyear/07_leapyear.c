//----------------------------------------------------------------------
// leapyear.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Main function: Accepts an int year as a command-line argument.
// Writes "True" to standard output if the year is a leap year, otherwise "False".
int main(int argc, char *argv[]) {
    // Check if a year argument is passed
    if (argc < 2) {
        printf("Usage: ./leapyear <year>\n");
        return 1;
    }

    int year = atoi(argv[1]);

    int isLeapYear = (year % 4 == 0);
    isLeapYear = isLeapYear && (year % 100 != 0);
    isLeapYear = isLeapYear || (year % 400 == 0);

    if (isLeapYear) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 07_leapyear 07_leapyear.c
// ./07_leapyear 2016
// True

// ./07_leapyear 1900
// False

// ./07_leapyear 2000
// True
