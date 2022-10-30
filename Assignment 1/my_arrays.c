#include <stdio.h>

#define SIZE 10

/*NOTE: THIS TAKES INTO CONSIDERATION THE ARRAY CONSISTING ONLY OF 1s, 2s, AND 3s as requested in the Assignment Documentation.*/

/*
TEST CASE 1: 1D array of unsigned positive ints of 3 types only (1,2,3) => check

TEST CASE 2: empty 1D array => Invalid array / check 

TEST CASE 3: 1D array of non-positive integers => check (Limited to median and sorting only)

TEST CASE 4: Invalid indices (out of bounds) => check

TEST CASE 5: 1D array of positive integers other than 1, 2, 3 => check (Limited to median and sorting only)
*/

int max(int n1, int n2);


/*
REQUIRES: 1D array of POSITIVE integers

EFFECTS: prints the values in accordance to their indices
*/

void printArray(int* a)
{
    if(sizeof(a) != 0)
    {
        printf("Index\tValue\n");
        for(int i = 0; i < SIZE; i++)
        {
            printf("%d\t%d\n", i, a[i]);
        }
    }
    else printf("Invalid array\n");
}

/*
REQUIRES: 1D array of POSITIVE integers

EFFECTS: prints the values and their frequency in terms of integers and asterisks
*/

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
        for(int j = 0; j < SIZE; j++)
        {
            if(a[j] == i)
            {
                count++;
            }
        }

        printf("%d\t%d\t\t", i, count);

        for(int k = 0; k < count; k++)
            printf("%c", '*');

        printf("\n");
    }
}

/*
REQUIRES: non-empty integer 1D array

EFFECTS: prints the elements of the array
*/

void printer(int* a)
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
        printf("\n");
}

/*
REQUIRES: 1D non-empty integer array, and two valid indices

EFFECTS: swap elements at designated indices
*/

void swapValues(int* array, int i1, int i2)
{
    if(array[i1] != NULL && array[i2] != NULL && sizeof(array) != 0)
    {
        int temp = array[i1];
        array[i1] = array[i2];
        array[i2] = temp;
    }
    else printf("Invalid index/array\n");
}

/*
REQUIRES: non-empty 1D integer array

EFFECTS: sort the array in increasing order (e.g., 1,2,3,4,5,6)
*/

void bubbleSort(int* array)
{
    if(sizeof(array) != 0)
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
    else printf("Invalid array\n");
}

/*
REQUIRES: non-empty 1D array of positive integers

EFFECTS: prints median
*/

void median(int* array)
{
    if(sizeof(array) != 0)
    {
        bubbleSort(array);
        for(int i = 0; i <= SIZE/2; i++)
        {
            if(i == SIZE/2)
            {
                printf("Median: %d\n", array[i]);
            }
        }
    }
    else printf("Invalid array\n");
}

/*
REQUIRES: non-empty 1D array of positive integers and the max function to check the most occuring element

EFFECTS: prints mode
*/

int mode(int* array)
{
    int countOne = 0, countTwo = 0, countThree = 0;
    int Max = 0;
    if(sizeof(array) != 0)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(array[i] == 1)
                countOne++;
            else if(array[i] == 2)
                countTwo++;
            else if(array[i] == 3)
                countThree++;
            else
            {
                printf("Invalid elements (must consist of 1s,2s, and 3s only!)\n");
                break;
            }
        }
        Max = max(countOne, max(countTwo,countThree));
        printf("Mode: %d\n", Max);
    }
    else printf("Invalid array\n");
    return Max;
}

/*
REQUIRES: none empty 1D array of ints and a valid size input

EFFECTS: returns 1 if sorted in increasing order, 0 if not
*/

int isSorted(int* array, int size)
{
    if(sizeof(array) != 0 && size > 0)
    {
    for(int i = 0; i < size - 1; i++)
    {
        if(array[i] > array[i+1])
        {
            return 0;
        }
    }
    printf("Sorted Array\n");
    return 1;
    }
    else printf("Invalid array / size\n");
}

/*
REQUIRES: none

EFFECTS: returns max of two inputs
*/

int max(int n1, int n2)
{
    return (n1 > n2) ? n1:n2;
}

int main()
{
    //Test Case: 1
    int a[SIZE] = {1,1,1,2,2,2,3,1,1,1};
    //Test Case: 2
    int b[SIZE];
    //Test Case: 3
    int c[SIZE] = {-1,-1,-1,-2,-2,-2,-3,-1,-1,-1};
    //Test Case: 5
    int d[SIZE] = {4,4,4,2,2,2,3,3,3,2};

    printArray(a);
    arrayHistogram(a);
    swapValues(a, 0, 3);
    printer(a);
    bubbleSort(a);
    median(a);
    mode(a);
    isSorted(a, SIZE);
    printer(a);

    // printArray(b);
    // arrayHistogram(b);
    // swapValues(b, 0, 3);
    // printer(b);
    // bubbleSort(b);
    // median(b);
    // mode(b);
    // isSorted(b, SIZE);
    // printer(b);

    // printArray(c);
    // arrayHistogram(c);
    // swapValues(c, 0, 3);
    // printer(c);
    // bubbleSort(c);
    // median(c);
    // mode(c);
    // isSorted(c, SIZE);
    // printer(c);

    // printArray(d);
    // arrayHistogram(d);
    // swapValues(d, 0, 3);
    // printer(d);
    // bubbleSort(d);
    // median(d);
    // mode(d);
    // isSorted(d, SIZE);
    // printer(d);

    return 0;
}