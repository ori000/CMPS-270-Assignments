#include <stdio.h>

#define SIZE 10

int max(int n1, int n2);

int main()
{
    int a[SIZE] = {1,1,1,2,2,2,3,3,3,1};

    // printf("%d",isSorted(a, SIZE));
    // printf("\n");
    
    // for(int i = 0; i < SIZE; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // median(a);
    // printf("\n");
    // swapValues(a, 0, 3);
    // for(int i = 0; i < SIZE; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // bubbleSort(a);
    // printf("%d",isSorted(a, SIZE));
    // printf("\n");
    // for(int i = 0; i < SIZE; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // mode(a);
    // printArray(&a);
    arrayHistogram(&a);
    // printer(&a);
    // swapValues();
    return 0;
}
void printArray(int* a)
{
        printf("Index\tValue\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\t%d\n", i, a[i]);
    }
}
void arrayHistogram(int* a)
{
    int countOne = 0, countTwo, countThree;

    for(int i = 0; i < SIZE; i++)
    {
        if(a[i] == 1)
            countOne++;
        else if(a[i] == 2)
            countTwo++;
        else 
            countThree++;
    }

    printf("Value\tFrequency\tHistogram\n");


    for(int i = 1; i <= 3; i++)
    {
        int count = 0;
        // char arrayChecker[10];
        for(int j = 0; j < SIZE; j++)
        {
            if(a[j] == i)
            {
                count++;
                // arrayChecker[j] = '*';
            }
        }
        printf("%d\t%d\t\t", i, count);
        for(int k = 0; k < count; k++)
            printf("%c", '*');
        printf("\n");
        // printer(&arrayChecker);
    }
}
void printer(int* a)
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%c", a[i]);
    }
        printf("\n");
}
void swapValues(int* array, int i1, int i2)
{
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}
void bubbleSort(int* array)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void median(int* array)
{
    bubbleSort(array);
    for(int i = 0; i <= SIZE/2; i++)
    {
        if(i == SIZE/2)
        {
            printf("Median: %d", array[i]);
        }
    }
}
void mode(int* array)
{
    int countOne = 0, countTwo = 0, countThree = 0;
    int Max = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(array[i] == 1)
            countOne++;
        else if(array[i] == 2)
            countTwo++;
        else countThree++;
    }
    Max = max(countOne, max(countTwo,countThree));
    printf("Mode: %d", Max);
}
int isSorted(int* array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(array[i] > array[i+1])
            return 0;
    }
    return 1;
}
int max(int n1, int n2)
{
    return (n1 > n2) ? n1:n2;
}