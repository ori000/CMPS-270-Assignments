#include <stdio.h>

int main()
{
    char a1 = 'a';
    char *a2 = a1;
    char *a3 = &a1;
    char *a4 = a3;
    char *a5;
    char *a6 = a5;
    char **a7 = a6;
    char **a8 = &a6;
    char **a9 = *a6;
    char a10 = &*a9;
    char *a11 = *&a10;

    char a12 = "HELlO";
    char *a13 = "HELLO";
    char a14[] = {"Hello"};
    char a15[] = "Hey";
    char* a16[] = {"hey", "hi"};
    char* a17[2][2] = {{"11","20"},{"54","rr4"}};
}

void function()
{
    printf("%s");
}