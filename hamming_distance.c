#include <stdio.h>


// int FindHammingDistance(int* n1, int* n2);
// int main()
// {
//     int n1 = 1, n2 = 0;

//     // printf("Enter n1:\n");
//     // scanf("%d", n1);
//     // printf("Enter n2:\n");
//     // scanf("%d", n2);

//     printf("%d",FindHammingDistance(&n1, &n2));

//     return 0;
// }

// int FindHammingDistance(int* num1, int* num2)
// {
//     int a1[8];
//     int a2[8];

//     for(int index = 0; index < 8; index++)
//     {
//         a1[index] = 0;
//         a2[index] = 0;
//     }

//     int countDifference = 0;
//     int z = 0, k = 0, i = 0;

//     printf("\na1: ");
//     while(a1[z] != '\0')
//     {
//         printf("%d ", a1[z]);
//         z++;
//     }
//     printf("\na2: ");
//     while(a2[k] != '\0')
//     {
//         printf("%d ", a2[k]);
//         k++;
//     }
//     printf("\n%d %d\n", z, k);

//     printf("num1 and num2 = %d, %d", *num1, *num2);

//     while(!(*num1 / 2 == 0 && *num2 / 2 == 0))
//     {
//         a1[i] = *num1 / 2;
//         *num1 = *num1 / 2;

//         a2[i] = *num2 / 2;
//         *num2 = *num2 / 2;
//         printf("check for loop 1");
//         i++;
//     }
//     for(int j = 7; j >= 0; j--)
//     {
//         if(a1[j] != a2[j])
//             countDifference++;
//     }
//     return countDifference;
// }

void findHammingDist(int* n1, int* n2);

int main()
{
    int n1, n2;
    scanf_s("%d", &n1);
    scanf_s("%d", &n2);
    while(n1 > -1 && n2 > -1)
    {
        if(sizeof(n1) != sizeof(int) || sizeof(n2) != sizeof(int))
            break;
        else
        {
            findHammingDist(&n1, &n2);
            scanf_s("%d", &n1);
            scanf_s("%d", &n2);
        }
    }
}
void findHammingDist(int* n1, int* n2)
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
    printf("%d\n", countDifference);
}