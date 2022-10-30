#include <stdio.h>
#include <stdlib.h>


/*
TEST CASE 1: two input arrays of char pointers of equal size => checked returns char pointer array with sorted elements

TEST CASE 2: two input arrays of char pointers of different sizes => checked returns char pointer array with sorted elements 

TEST CASE 3: two input arrays of char pointers of equal size but different elements => checked returns char pointer array with sorted elements

TEST CASE 4: two input arrays of char pointers of different size but equal elements => checked returns char pointer array with sorted elements

TEST CASE 5: two input arrays of char pointers of different size and different elements => checked returns char pointer array with sorted elements

TEST CASE 6: two empty input arrays of char pointers => checked returns empty char pointer array

TEST CASE 7: one empty and one non-empty input array of char pointers returns non-empty char pointer array


*/

char** merge(char* a1[], char* a2[], int sizeA1, int sizeA2);
int Max(int n1, int n2);
int Min(int n1, int n2);

int checkA1 = 0;
int checkA2 = 0;
int checkSubA1 = 0;
int checkSubA2 = 0;

/*
REQUIRES: nothing

Effects: call merge function
*/
int main()
{
    char* a1[] = {"ab", "ac"};
    char* a2[] = {"za", "zb", "zcccc"};

    char* a3[] = {""};
    char* a4[] = {""};

    int sizeA1 = sizeof(a1) / sizeof(char*);
    int sizeA2 = sizeof(a2) / sizeof(char*);

    int sizeA3 = sizeof(a3) / sizeof(char*);
    int sizeA4 = sizeof(a4) / sizeof(char*);

    merge(a1, a2, sizeA1, sizeA2);

    merge(a3, a4, sizeA3, sizeA4);

    return 0;
}

/*
REQUIRES: non empty arrays of char pointers (string arrays)

EFFECTS: concat the input arrays into one based on their size and sorting of chars (ASCII values)
*/
char** merge(char* a1[], char* a2[], int sizeA1, int sizeA2)
{
    char** a3 = (char**)malloc(sizeof(char*)*(sizeA1 + sizeA2));

    if(sizeA1 == sizeA2)    //Case 1
    {
        for(int i = 0; i < (sizeA1 || sizeA2); i++)
        {
            for(int j = 0; j < Min(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)); j++)    //Bounded to smaller element in size
            {
                if(*(a1[j]) <= *(a2[j]))
                {
                    *(a3[j] + i) = *(a1[j]);
                }
                else
                {
                    *(a3[j] + i) = *(a2[j]);
                }
            }
            if(Max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a1[i])) / sizeof(char*)))   //Insert the remaining characters of the larger element in size
            {
                for(int k = 0; k < (sizeof(*(a1[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a2[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a2[i])) / sizeof(char*) + k]);
                }
            }
            else if(Max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a2[i])) / sizeof(char*)))   //Insert the remaining characters of the larger element in size
            {
                for(int k = 0; k < (sizeof(*(a2[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a1[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a1[i])) / sizeof(char*) + k]);
                }
            }
        }
        printf("Case 1 checked");
    }
    else if(sizeA1 < sizeA2)    //Case 2
    {
        for(int i = 0; i < (sizeA1); i++)
        {
            for(int j = 0; j < Min(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)); j++)
            {
                if(*(a1[j]) <= *(a2[j]))
                {
                    *(a3[j] + i) = *(a1[j]);
                }
                else
                {
                    *(a3[j] + i) = *(a2[j]);
                }
            }
            if(Max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a1[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a1[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a2[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a2[i])) / sizeof(char*) + k]);
                }
            }
            else if(Max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a2[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a2[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a1[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a1[i])) / sizeof(char*) + k]);
                }
            }
        }
        printf("Case 2 checked");
        a3[sizeA2 - 1] = a2[sizeA2 - 1];    //Assign the last element of the bigger array to a3
        printf("Case 2.1 checked");
    }
    else if(sizeA1 > sizeA2)    //Case 3
    {
        for(int i = 0; i < (sizeA2); i++)
        {
            for(int j = 0; j < Min(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)); j++)
            {
                if(*(a1[j]) <= *(a2[j]))
                {
                    *(a3[j] + i) = *(a1[j]);
                }
                else
                {
                    *(a3[j] + i) = *(a2[j]);
                }
            }
            if(Max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a1[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a1[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a2[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a2[i])) / sizeof(char*) + k]);
                }
            }
            else if(Max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a2[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a2[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a1[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a1[i])) / sizeof(char*) + k]);
                }
            }
        }
        a3[sizeA1 - 1] = a1[sizeA1 - 1];    //Assign the last element of the bigger array to a3
    }
    return a3;
}

/*
REQUIRES: nothing

EFFECTS: return the min of 2 input ints
*/
int Min(int n1, int n2)
{
    if(n1 > n2)
    {
        checkA1 = 1;
        return n2;
    }
    else if(n2 > n1)
    {
        checkA2 = 1;
        return n1;
    }
}

/*
REQUIRES: nothing

EFFECTS: return the max of 2 input ints
*/
int Max(int n1, int n2)
{
    if(n1 > n2)
    {
        checkSubA1 = 1;
        return n1;
    }
    else if(n2 > n1)
    {
        checkSubA2 = 1;
        return n2;
    }
}
