#include <stdio.h>
#include <stdlib.h>

unsigned int msb(int* v);
unsigned int lsb(int* v);

/*
TEST CASE 1: Positive integer => check

TEST CASE 2: Same values => check

TEST CASE 3: Power of 2 => check

TEST CASE 4: 0 or 1 => check
*/

int main()
{
    unsigned int value;

    printf("Enter the value in decimal form:\n");
    scanf("%d \n", &value);
    printf("msb: %d\n", msb(&value));
    printf("lsb: %d\n", lsb(&value));
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