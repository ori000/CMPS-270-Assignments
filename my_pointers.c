// #include <stdio.h>

// char* merge(char* a1, char* a2, int size1, int size2);

// int main()
// {
//     char* a1[] = {"ab", "ac"};
//     char* a2[] = {"za", "zb", "zzzzc"};

//     int size1 = sizeof(a1)/sizeof(char*);
//     int size2 = sizeof(a2)/sizeof(char*);

//     // printf("%d\n", size1);
//     // printf("%d\n", size2);
//     // printf("%d\n", sizeof(char*));
//     // printf("%d\n", sizeof(typeof(a1)));

//     merge(*a1, *a2, size1, size2);

//     return 0;
// }

// char* merge(char* a1, char* a2, int size1, int size2)
// {
//     char* a3;
//     printf("%d\n", size1);
//     printf("%d\n", size2);

//     //Questions

//     printf("%s\n", a1+6);
//     // printf("%s\n", a2[0]);
//     printf("%c\n", *a1);
//     printf("%c\n", &a1[0]);
//     printf("%c\n", a1[4]);
//     printf("%c\n", a1[1]);
//     printf("%c\n", a1[2]); //WHY EMPTY
//     printf("%c\n", a1[3]);

//     for(int i = 0; i < 5; i++)
//         printf("%c", a1[i]);

//     int s1 = (int)malloc(size1*sizeof(char*));
//     int s2 = (int)malloc(size2*sizeof(char*));

//     printf("%d\n", s1);
//     printf("%d\n", s2);

//     for(int i = 0; i < size1; i++)
//     {
//         for(int j = 0; j < i; j++)
//         {
            
//         }
//     }
// }

#include <stdio.h>
#include <stdlib.h>

void merge(char* a1[], char* a2[], int sizeA1, int sizeA2);
int max(int n1, int n2);
int min(int n1, int n2);

int checkA1 = 0;
int checkA2 = 0;
int checkSubA1 = 0;
int checkSubA2 = 0;

int min(int n1, int n2)
{
    if(n1 > n2)
    {
        checkA1 = 1;
        return n2;
    }
    else if(n2 > n1)
    {
        checkA2 = 1;
        return n1;
    }
    else return 0;
}

int max(int n1, int n2)
{
    if(n1 > n2)
    {
        checkSubA1 = 1;
        return n1;
    }
    else if(n2 > n1)
    {
        checkSubA2 = 1;
        return n2;
    }
}


int main()
{
    char* a1[] = {"ab", "ac"};
    char* a2[] = {"za", "zb", "zcccc"};

    int sizeA1 = sizeof(a1) / sizeof(char*);
    int sizeA2 = sizeof(a2) / sizeof(char*);

    // merge(a1, a2, sizeA1, sizeA2);

    printf("%s \n", a1[sizeA1 - 1]);
    
    printf("%s \n", *(a1+0));

    return 0;
}

void merge(char* a1[], char* a2[], int sizeA1, int sizeA2)
{
    // char* a3[] = (char*)malloc(sizeof(char)*(sizeA1 + sizeA2));
    char* a3[7];

    if(sizeA1 == sizeA2)
    {
        for(int i = 0; i < (sizeA1 || sizeA2); i++)
        {
            for(int j = 0; j < min(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)); j++)
            {
                if(*(a1[j]) <= *(a2[j]))
                {
                    *(a3[j] + i) = *(a1[j]);
                }
                else
                {
                    *(a3[j] + i) = *(a2[j]);
                }
            }
            if(max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a1[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a1[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a2[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a2[i])) / sizeof(char*) + k]);
                }
            }
            else if(max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a2[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a2[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a1[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a1[i])) / sizeof(char*) + k]);
                }
            }
        }
    }
    else if(sizeA1 < sizeA2)
    {
        for(int i = 0; i < (sizeA1); i++)
        {
            for(int j = 0; j < min(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)); j++)
            {
                if(*(a1[j]) <= *(a2[j]))
                {
                    *(a3[j] + i) = *(a1[j]);
                }
                else
                {
                    *(a3[j] + i) = *(a2[j]);
                }
            }
            if(max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a1[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a1[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a2[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a2[i])) / sizeof(char*) + k]);
                }
            }
            else if(max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a2[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a2[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a1[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a1[i])) / sizeof(char*) + k]);
                }
            }
        }
        a3[sizeA2 - 1] = a2[sizeA2 - 1];
    }
    else if(sizeA1 > sizeA2)
    {
        for(int i = 0; i < (sizeA2); i++)
        {
            for(int j = 0; j < min(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)); j++)
            {
                if(*(a1[j]) <= *(a2[j]))
                {
                    *(a3[j] + i) = *(a1[j]);
                }
                else
                {
                    *(a3[j] + i) = *(a2[j]);
                }
            }
            if(max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a1[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a1[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a2[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a2[i])) / sizeof(char*) + k]);
                }
            }
            else if(max(sizeof(*(a1[i])) / sizeof(char*), sizeof(*(a2[i])) / sizeof(char*)) == (sizeof(*(a2[i])) / sizeof(char*)))
            {
                for(int k = 0; k < (sizeof(*(a2[k])) / sizeof(char*)); k++)
                {
                    *(a3[sizeof(*(a1[i])) / sizeof(char*) + k]) = *(a1[sizeof(*(a1[i])) / sizeof(char*) + k]);
                }
            }
        }
        a3[sizeA1 - 1] = a1[sizeA1 - 1];
    }
    for(int i = 0; i < (sizeA1+sizeA2); i++)
        printf("%s ", a3[i]);
}

// int min(int n1, int n2)
// {
//     if(n1 > n2)
//     {
//         checkA1 = 1;
//         return n2;
//     }
//     else if(n2 > n1)
//     {
//         checkA2 = 1;
//         return n1;
//     }
// }

// int max(int n1, int n2)
// {
//     if(n1 > n2)
//     {
//         checkSubA1 = 1;
//         return n1;
//     }
//     else if(n2 > n1)
//     {
//         checkSubA2 = 1;
//         return n2;
//     }
// }
