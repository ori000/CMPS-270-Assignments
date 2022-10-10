#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMENSION_1 3
#define DIMENSION_2 3

/*NOTE: After thorough consultation with the TAs, I understood that inputing the array manually is sufficent (i.e., no need for a scanner)*/

/*
TEST CASE 1: 

TEST CASE 2:

TEST CASE 3:

TEST CASE 4:

*/

char** concat(char* a[DIMENSION_1][DIMENSION_2], int size);

int main()
{
    char* a[DIMENSION_1][DIMENSION_2] = {{"one", "two", "New2"},{"three", "four", "New2"}, {"five", "six", "New3"}};
    int size = sizeof(a) / sizeof(char*);

    concat(a, size);

    free(size);
    free(a);
    return 0;
}

/*
REQUIRES: array of character pointers (2D string array), the size of both dimensions and the number of elements in the array

EFFECTS:  returns a pointer of character pointers (1D string array) that is a result of concatenation of the input array's elements
*/
char** concat(char* a[DIMENSION_1][DIMENSION_2], int size)
{
    // char** a2 = (char**)malloc(size * sizeof(char**));
    char** a2;

    for(int i = 0; i < DIMENSION_1; i++)
    {
        a2[i] = malloc(sizeof(a[DIMENSION_1][DIMENSION_2])*sizeof(char**));
    }
    int k = 0;

    for(int i = 0; i < DIMENSION_1; i++)
    {
        for(int j = 0; j < DIMENSION_2; j++)
        {
            // a2[k] = (char*)a[i][j];
            // k++;
            strcat(a2[k], a[i][j]);
        }
        k++;
    }

    printf("[");

    for(int i = 0; i < DIMENSION_1; i++)
    {
        printf("%s ,", a2[i]);
    }

    printf("]\n");

    return a2;
    free(k);
    free(a2);
}