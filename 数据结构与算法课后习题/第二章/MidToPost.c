#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CaculateInLine(char* line);
int main()
{
    char line[] = "8-(3+5-4/2)*2/3";
    printf("%s\n", CaculateInLine(line));

    return 0;
}

char* CaculateInLine(char* line)
{
    int length = strlen(line);
    char* ans = (char*)malloc(sizeof(char) * length);
    int j = 0;
    int* NumStack = (int*)malloc(sizeof(int) * length);
    int cur1 = -1;
    char* OpeStack = (char*)malloc(sizeof(int) * length);
    int cur2 = -1;

    __int8_t flag = 0;
    __int8_t i = 0;
    while (i < length)
    {
        if ('0' <= line[i] && line[i] <= '9')
        {
            ans[j++] = line[i++];
        }
        else
        {
            if (line[i] == '(')
            {
                OpeStack[++cur2] = '(';
                flag = 1;
            }
            else if (line[i] == ')')
            {
                if (flag == 1)
                {
                    while (OpeStack[cur2] != '(')
                        ans[j++] = OpeStack[cur2--];
                    
                    cur2--;
                    flag = 0;
                }
                else 
                {
                    printf("Error!\n");
                    exit(-1);
                }
            }
            else if (line[i] == '*' || line[i] == '/')
            {
                if (cur2 != -1 && OpeStack[cur2] != '(' && OpeStack[cur2] != '+' && OpeStack[cur2] != '-')
                    ans[j++] = OpeStack[cur2--];
                
                OpeStack[++cur2] = line[i];
            }
            else
            {
                if (cur2 != -1 && OpeStack[cur2] != '(')
                    ans[j++] = OpeStack[cur2--];
                
                OpeStack[++cur2] = line[i];
            }
            i++;
        }  
    }

    while (cur2 != -1)
    {
        char chr = OpeStack[cur2];
        int num1 = NumStack[cur1];
        int num2 = NumStack[cur1];
        ans[j++] = OpeStack[cur2--];
    }
    
    ans[j] = 0;
    free(NumStack);
    NumStack = NULL;
    free(OpeStack);
    OpeStack = NULL;
    return ans;
}
