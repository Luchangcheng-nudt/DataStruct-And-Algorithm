//Programer: Luchangcheng  2020/1/15
//Compiler: gcc version 8.1.0 (x86_64-win32-sjlj-rev0, Built by MinGW-W64 project)  WinX64  C11 Standard
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GenNext(char p[], int next[]);
int KMP(char s[], char p[], int next[]);
int main()
{
    char s[1000] = {0};
    char p[1000] = {0};
    scanf("%s", s);
    scanf("%s", p);
    int* next = (int*)malloc(sizeof(char) * strlen(p));
    GenNext(p, next);
    printf("%d\n", KMP(s, p, next));

    free(next);
    return 0;
}

void GenNext(char p[], int next[])
{
    int i = 0;
    int j = -1;
    size_t length = strlen(p) - 1;
    next[0] = -1;

    while (i < length)
    {
        while (j != -1 && next[i] != next[j])
            j = next[j];
        i++;
        j++;
        if (p[i] == p[j])
            next[i] = next[j];
        else 
            next[i] = j;
    }
}

int KMP(char s[], char p[], int next[])
{
    int i = 0;
    int j = 0;
    size_t s_size = strlen(s);
    size_t p_size = strlen(p);

    while (i < s_size && j < p_size)
    {
        while (j != -1 && s[i] != p[j])
            j = next[j];
        i++;
        j++;
    }

    if (j == p_size)
        return i - j;
    return -1;
}
