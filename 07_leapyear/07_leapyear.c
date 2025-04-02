//----------------------------------------------------------------------
// 07_leapyear.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printLeapYearStatus(int isLeap) {
    printf("%s\n", isLeap ? "True" : "False");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./leapyear <year>\n");
        return 1;
    }

    int year = atoi(argv[1]);
    int leapStatus = isLeapYear(year);
    printLeapYearStatus(leapStatus);

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
