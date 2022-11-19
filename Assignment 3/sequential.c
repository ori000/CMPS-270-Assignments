#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *array;
int length;
int count;

int count1s ()
{
    int i;
    count = 0;
    for (i=0; i<length; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    return count;
}

int main ()
{   
    srand(time(NULL));
    length = 100000;
    array = (long*)malloc(sizeof(long)*length);
    for(long i = 0; i < length; i++)
    {
        array[i] = rand() % 5;
    }
    printf("Count of Ones: %d", count1s());
}