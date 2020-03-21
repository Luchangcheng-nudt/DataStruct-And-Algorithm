#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP(char *t, char *p);
void GenNext(char* p, int next[]);
int main()
{
    int index = KMP("abcabca", "cab");
    printf("%d\n", index);

    return 0;
}

void GenNext(char* p, int next[])
{
    int i = 1;
    int k = -1;
    next[0] = -1;
    int len = strlen(p);

    while (i < len)
    {
        while (k > -1 && p[k] != p[i-1])
            k = next[k];
        k++;
        if (p[k] != p[i])
            next[i] = k;
        else 
            next[i] = next[k];
        i++;
    }
}

int KMP(char *t, char *p)
{
    int t_length = strlen(t);
    int p_length = strlen(p);
    int *next = (int*)malloc(sizeof(int) * p_length);
    GenNext(p, next);
    int i = 0;
    int j = 0;

    while (i < t_length && j < p_length)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        else if (next[j] > -1)
            j = next[j];
        else 
        {
            j = 0;
            i++;
        }
    }

    free(next);
    if (j >= p_length)
        return i - j;
    return -1;
}