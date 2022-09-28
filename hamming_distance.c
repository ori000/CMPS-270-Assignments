#include <stdio.h>

int FindHammingDistance(int n1, int n2);
int main()
{
    int n1, n2;

    printf("Enter n1:\n");
    scanf("%d", &n1);
    printf("Enter n2:\n");
    scanf("%d", &n2);

    printf("%d",FindHammingDistance(n1, n2));

    return 0;
}

int FindHammingDistance(int num1, int num2)
{
    int* a1[8];
    int* a2[8];

    int countDifference = 0;

    for(int i = 7; i >= 0; i--)
    {
        *a1[i] = num1 % 2;
        num1 = num1 % 2;

        *a2[i] = num2 % 2;
        num2 = num2 % 2;
    }
    for(int j = 7; j >= 0; j--)
    {
        if(*a1[j] != *a2[j])
            countDifference++;
    }
    printf("a1: %d\n", *a1);
    printf("a2: %d\n", *a2);
    return countDifference;
}