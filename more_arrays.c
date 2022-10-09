// #include <stdio.h>

// void concat(char* a[32][32]);

// int main()
// {
//     char* a[32][32] = {{"HELLO"},{"PROGRAMMER", "HEY"},{"WHAT", "IS", "UP"}};
//     // for(int i = 0; i < 32; i++)
//     // {
//     //     for(int j = 0; j < 32; j++)
//     //     {
//     //         if(a[i][j] != NULL)
//     //         printf("%s ", a[i][j]);
//     //     }
//     // }
//     concat(&a);
// }

// void concat(char* a[32][32])
// {
//     char* a2[32];
//     // printf("%s \n", a);
//     int k = 0;

//     for(int i = 0; i < 32; i++)
//     {
//         for(int j = 0; j < 32; j++)
//         {
//             if(a[i][j] != NULL){
//             a2[k] = a[i][j];
//             printf("a: %s   a2: %s\n", a[i][j], a2[k]);
//             k++;}
//         }
//     }
//     k = 0;
//     while(a2[k] != NULL){
//         printf("%s", a2[k]);
//         k++;}
// }
// #include <stdio.h>

// char* concat(char** a, int num);

// int main()
// {
//     // char* a[8];
//     // a[0] = "hello";
//     // printf("%s", a[0]);

//     //QUESTION
//     char** a;
//     a[0] = "hello";
//     printf("%s", a[0][0]);

// //     char** a = {{"E11", "E12"}, {"E21", "E22"}};

// //     int size = sizeof(a)/sizeof(char*);
// //     concat(a, size);
// // }
// }
// char* concat(char** a, int num)
// {
//     char** aray;
//     array = (char**)malloc*(sizeof(char**) * 2);
// }

#include <stdio.h>
#include <stdlib.h>

#define DIMENSION_1 2
#define DIMENSION_2 2

void concat(char* a[DIMENSION_1][DIMENSION_2], int size);

int main()
{
    char* a[DIMENSION_1][DIMENSION_2] = {{"one", "two"},{"three", "four"}};
    int size = sizeof(a) / sizeof(char*);

    concat(a, size);

    free(size);
    free(a);
    return 0;
}

void concat(char* a[DIMENSION_1][DIMENSION_2], int size)
{
    char** a2 = (char**)malloc(size * sizeof(char**));
    int k = 0;

    for(int i = 0; i < DIMENSION_1; i++)
    {
        for(int j = 0; j < DIMENSION_2; j++)
        {
            a2[k] = (char*)a[i][j];
            k++;
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%s ", a2[i]);
    }
    free(k);
    free(a2);
}