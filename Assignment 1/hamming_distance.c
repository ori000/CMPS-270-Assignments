#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <math.h>

/*
Test Case 1: Positive input => checked print hamming difference (e.g., 0 3 => 2)

Test Case 2: Non-positive input => checked break loop (e.g., -1 -2)

Test Case 3: Non-integral input => checked break loop (e.g., "string" "string")

Test Case 4: Two equal input => difference: 0 => checked print 0 (e.g., 4 4)

Test Case 5: One positive and one negative input => checked break loop (e.g., 4 -2)

Test Case 6: Input is a long or other data types => break loop => checked (e.g., 1231242121413314413 4134322243726852)
*/

void findHammingDist(int* n1, int* n2);

/*
REQUIRES: nothing

EFFECTS: scans for user input and calls the findHammingDist function (after checking validity of the input)
*/
int main()
{
    int n1, n2;
    int countOne, countTwo;

    printf("Input two integers using the following format: n1 n2\n");

    if(scanf_s("%d %d", &n1, &n2) == 2 && n1 > -1 && n2 > -1)
    {
        printf("Checked as a number. Kindly input any int to continue.\n");
        while(n1 > -1 && n2 > -1)
        {
            if(scanf_s("%d %d", &n1, &n2) == 2)
                findHammingDist(&n1, &n2);
            else
            {
                printf("Invalid input, cannot input a non integral value (e.g., char, long)\nAborting");
                break;
            }
        }
    } 
    else 
    {
        printf("Invalid input: Not a positive int \n Aborting");

    }
}

/*
REQUIRES: Two positive integer inputs
EFFECTS: Prints the difference between the binary representation of the two positive integral inputs
*/
void findHammingDist(int* n1, int* n2)
{
    if(*n1 >= 0 && *n2 >= 0)
    {
        int countDifference = 0;
        while(*n1 > 0 || *n2 > 0)
        {
            if(*n1 % 2 != *n2 % 2)
            {
                countDifference++;
            }
            *n1 /= 2;
            *n2 /= 2;
        }
        printf("Difference: %d\n", countDifference);
    }
    else printf("Invalid numbers, should input positive integers\n");
}