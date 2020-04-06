#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int MoveByGS(int *suffix, char *prefix, int len, int BadCharIndex);
void generateBadChar(char *Pattern, int *BadCharHash); //(模式串字符b，模式串长度m，模式串的哈希表)
void generateGS(char *Pattern, int *suffix, char *prefix); 
int BMSearch(char *MainString, char *Pattern);
int main()
{
    printf("%d\n", BMSearch("1234356", "343"));

    return 0;
}

void generateBadChar(char *Pattern, int *BadCharHash)
{
    int m = strlen(Pattern);
    int i = 0;
    for (i = 0; i < m; i++)
        BadCharHash[i] = -1;
    
    for (i = 0; i < m; i++)
        BadCharHash[Pattern[i]] = i;
}

int BMSearch(char *MainString, char *Pattern)
{
    int *BadCharHash = (int*)malloc(sizeof(int) * SIZE);
    generateBadChar(Pattern, BadCharHash);

    int MainStringLength = strlen(MainString);
    int PatternLength = strlen(Pattern);
    
    int i = 0, j = 0;
    while (i < MainStringLength - PatternLength + 1)
    {
        for (j = PatternLength - 1; j >= 0; j--)
        {
            if (MainString[i + j] != Pattern[j])
                break;
        }
        if (j < 0)
            return i;
        i += (j - BadCharHash[MainString[i + j]]);
    }

    return -1;
}

void generateGS(char *Pattern, int *suffix, char *prefix)
{
    int i = 0, j = 0, k = 0;
    int len = strlen(Pattern);
    for (i = 0; i < len; i++)
    {
        suffix[i] = -1;
        prefix[i] = 0;
    }

    for (i = 0; i < len - 1; i++)
    {
        j = i;
        k = 0;
        while (j >= 0 && Pattern[j] == Pattern[len - 1 - k])
        {
            j--;
            k++;
            suffix[k] = j + 1;
        }
        if (j < 0)
            prefix[k] = 1;
    }
}

int MoveByGS(int *suffix, char *prefix, int len, int BadCharIndex)
{
    int GoodSufLen = len - 1 - BadCharIndex;
    if (suffix[GoodSufLen] > 0)
        return BadCharIndex - suffix[GoodSufLen] + 1
}
