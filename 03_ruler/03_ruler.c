//----------------------------------------------------------------------
// 03_ruler.c (with static and const keywords)
//----------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

static void combineRuler(char *ruler, const int num) {
    char temp[100];
    strcpy(temp, ruler);
    sprintf(ruler, "%s %d %s", temp, num, temp);
}

static void buildRulerPattern(char *ruler, const int level) {
    strcpy(ruler, "1");
    for (int i = 2; i <= level; i++) {
        combineRuler(ruler, i);
    }
}

int main(void) {
    char ruler[100];

    for (int i = 1; i <= 4; i++) {
        buildRulerPattern(ruler, i);
        printf("%s\n", ruler);
    }

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 03_ruler 03_ruler.c
// ./03_ruler
// 1
// 1 2 1
// 1 2 1 3 1 2 1
// 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
