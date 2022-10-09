#include <stdio.h>
#include <stdlib.h>

int msb(int* v);
int lsb(int* v);

int main()
{
    int value;

    printf("Enter the value in decimal form:\n");
    scanf("%d \n", &value);
    printf("msb: %d\n", msb(&value));
    printf("lsb: %d\n", lsb(&value));
}

int msb(int* value)
{
    int counter = 0;
    int aSize = 0;
    int v = *value;

    while(v != 1)
    {
        v /= 2;
        aSize++;
    }

    v = *value;
    int* array = (int*) malloc(aSize * sizeof(int));

    // for(int i = 0 ; i < aSize; i++)
    //     array[i] = (int)malloc(sizeof(int));

    for(int i = aSize; i >= 0; i--)
    {
        array[i] = v % 2;
        v /=2;
    }

    // for(int i = 0; i < aSize; i++)
    //     printf("%d ", array[i]);

    while(array[counter] != 1)
    {
        counter++;
    }

    return counter;
}

int lsb(int* value)
{
    int counter = 0;
    int aSize = 0;
    int v = *value;

    while(v != 1)
    {
        v /= 2;
        aSize++;
    }

    v = *value;
    int* array = (int*)malloc(aSize * sizeof(int));

    for(int i = aSize; i >= 0; i--)
    {
        array[i] = v % 2;
        v /=2;
    }

    while(array[aSize - counter] != 1)
    {
        counter++;
    }

    return aSize - 1 - counter;
}

// int msb(int* value)
// {
//     int array[32];
//     int counter = 0;
//     int j = 0;
    
//     for(int i = 31; i >= 0; i--)
//     {
//         array[i] = *value % 2;
//         *value /= 2;
//     }
//     // for(int j = 32; j >= 0; j--)
//     // {
//     //     if(array[j] == 1)
//     //     {
//     //         counter++;
//     //         break;
//     //     }
//     //     else counter++;
//     // }
//     while(array[j] != 1)
//     {
//         counter++;
//         j++;
//     }
//     for(int i = 0; i < 32; i++)
//     {
//         printf("msb: %d", array[i]);
//     }
//         printf("\n");
//     return 32 - counter - 1;
// }

// int lsb(int* value)
// {
//     int array[32];
//     int counter = 0;
//     int j = 0;
    
//     for(int i = 31; i >= 0; i--)
//     {
//         array[i] = *value % 2;
//         *value /= 2;
//     }
//     // for(int j = 0; j < 32; j++)
//     // {
//     //     if(array[j] == 1)
//     //     {
//     //         counter++;
//     //         break;
//     //     }
//     //     else counter++;
//     // }
//     while(array[j] == 0)
//     {
//         counter++;
//         j++;
//     }
//     for(int i = 0; i < 32; i++)
//     {
//         printf("lsb: %d ", array[i]);
//     }
//         printf("\n");
//     return 32 - counter - 1;
// }