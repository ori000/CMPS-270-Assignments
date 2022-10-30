#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMENSION_1 2
#define DIMENSION_2 3

#define DIMENSION_3 4
#define DIMENSION_4 4

#define DIMENSION_5 0
#define DIMENSION_6 0

#define DIMENSION_7 1
#define DIMENSION_8 1

/*NOTE: After thorough consultation with the TAs, I understood that inputing the array manually is sufficent (i.e., no need for a scanner)*/

/*
TEST CASE 1: Non Empty 2D array input of same dimension => checked

TEST CASE 2: Non Empty 2D array input of diff dimension => checked

TEST CASE 3: Empty 2D array input of same dimension => checked (Syntax error)

TEST CASE 4: 2D array of dimension 1 => checked

*/

char** concat(char* a[DIMENSION_1][DIMENSION_2], int size);

int main()
{   //TEST CASE 1
    char* a[DIMENSION_1][DIMENSION_2] = {{"one", "two", "New2"},{"three", "four", "New2"}};
    int size = sizeof(a) / sizeof(char*);
    //TEST CASE 2
    char* a2[DIMENSION_3][DIMENSION_4] = {{"one", "two", "New2"},{"three", "four", "New2"}, {"One", "Two", "nine", "Seven"}};
    int size2 = sizeof(a2) / sizeof(char*);
    //TEST CASE 3
    //char* a3[DIMENSION_5][DIMENSION_6] = {};
    //TEST CASE 4
    char* a4[DIMENSION_7][DIMENSION_8] = {"one"};

    concat(a, size);
    concat(a2, size);
    concat(a4, size);

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
    if(sizeof(a[DIMENSION_1][DIMENSION_2]) > 0)
    {
    char** a2 = (char**)malloc(size * sizeof(char**));
    int k = 0;

    for(int i = 0; i < DIMENSION_1; i++)
    {
        for(int j = 0; j < DIMENSION_2; j++)
        {
            a2[k] = (char*)a[i][j];
            k++;
        }
    }

    printf("[");

    for(int i = 0; i < size; i++)
    {
        if(i == size - 1)
        {
            printf("%s", a2[i]);
            break;
        }
        if(i % DIMENSION_2 == 0 && i != 0)
            printf(", ");
        printf("%s ", a2[i]);
    }

    printf("]\n");

    return a2;
    free(k);
    free(a2);
    }
    else printf("Invalid array!");
}