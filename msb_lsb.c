#include <stdio.h>
#include <stdlib.h>

unsigned int msb(int* v);
unsigned int lsb(int* v);

/*
TEST CASE 1: Positive integer => checked (e.g., 10)

TEST CASE 2: Power of 2 => checked (e.g., 4)

TEST CASE 3: 0 or 1 => checked

TEST CASE 4: Negative integer => checked (e.g., -10)

TEST CASE 5: Non integral input  (e.g., "string")
*/

/*
REQUIRES: 2 valid inputs in order to call the functions (first input checks the validity (i.e., if of type int) and the second one for C's outdated convention)

*/
int main()
{
    unsigned int value;

    printf("Enter the value in decimal form:\n");
    if(scanf("%d \n", &value) == 1)
    {
    printf("msb: %d\n", msb(&value));
    printf("lsb: %d\n", lsb(&value));
    }
    else printf("Invalid input");
}

/*
REQUIRES: unsigned int

EFFECTS: return position of the most significant bit using bitwise operators
*/
unsigned int msb(int* value)
{
    unsigned int val = *value;
    int pos = 0;

    while(val >>= 1)
        pos++;

    return pos;
}

/*
REQUIRES: unsigned int

EFFECTS: return position of the least significant bit using bitwise operators
*/
unsigned int lsb(int* value)
{

    unsigned int val = *value;
    int pos = 0;

    while(!(val & 1))
    {
        val >>= 1;
        pos++;
    }

    return pos;
}