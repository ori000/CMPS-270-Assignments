#include <stdio.h>

int msb(int v);
int lsb(int v);

int main()
{
    int value;

    printf("Enter the value in decimal form: %d\n");
    scanf("%d", &value);
    printf("msb: %d\n", msb(&value));
    printf("lsb: %d\n", lsb(&value));
}

int msb(int value)
{
    int array[32];
    int counter = 0;
    
    for(int i = 31; i >= 0; i--)
    {
        array[i] = value % 2;
        value %= 2;
    }
    for(int j = 32; j >= 0; j--)
    {
        if(array[j] == 1)
        {
            counter++;
            break;
        }
        else counter++;
    }
    return counter;
}

int lsb(int value)
{
    int array[32];
    int counter = 0;
    
    for(int i = 0; i < 32; i++)
    {
        array[i] = value % 2;
        value %= 2;
    }
    for(int j = 0; j < 32; j++)
    {
        if(array[j] == 1)
        {
            counter++;
            break;
        }
        else counter++;
    }
    return counter;
}