//----------------------------------------------------------------------
// ruler.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

// Function to build the ruler pattern.
void buildRuler(char *ruler, int num) {
    char temp[100];
    strcpy(temp, ruler);
    sprintf(ruler, "%s %d %s", temp, num, temp);  // Combine the parts.
}

// Main function: Prints the ruler patterns.
int main(void) {
    char ruler1[100] = "1";
    char ruler2[100];
    char ruler3[100];
    char ruler4[100];

    // Build the rulers using the buildRuler function.
    strcpy(ruler2, ruler1);
    buildRuler(ruler2, 2);

    strcpy(ruler3, ruler2);
    buildRuler(ruler3, 3);

    strcpy(ruler4, ruler3);
    buildRuler(ruler4, 4);

    // Print the ruler patterns.
    printf("%s\n", ruler1);
    printf("%s\n", ruler2);
    printf("%s\n", ruler3);
    printf("%s\n", ruler4);

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o ruler ruler.c
// ./ruler
// 1
// 1 2 1
// 1 2 1 3 1 2 1
// 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
