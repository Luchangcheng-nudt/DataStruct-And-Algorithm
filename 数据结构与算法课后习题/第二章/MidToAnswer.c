#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CaculateInLine(char* line);
int main()
{
    char line[] = "8-(3+5-4/2)*2/3";
    printf("%d\n", CaculateInLine(line));

    return 0;
}

int CaculateInLine(char* line)
{
    int length = strlen(line);
    int* NumStack = (int*)malloc(sizeof(int) * length);
    int cur1 = -1;
    char* OpeStack = (char*)malloc(sizeof(int) * length);
    int cur2 = -1;

    __int8_t flag = 0;
    __int8_t i = 0;
    int num = 0;
    while (i < length)
    {
        if ('0' <= line[i] && line[i] <= '9')
        {
            while (i < length && '0' <= line[i] && line[i] <= '9')
            {
                num = num * 10 + (line[i] - '0');
                i++;
            }
            NumStack[++cur1] = num;
            num = 0;
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
                    {
                        char chr = OpeStack[cur2];
                        int num1 = NumStack[cur1];
                        int num2 = NumStack[cur1];
                        switch (chr)
                        {
                        case '+':
                            NumStack[++cur1] = num2 + num1;
                            break;
                        case '-':
                            NumStack[++cur1] = num2 - num1;
                            break;
                        case '*':
                            NumStack[++cur1] = num2 * num1;
                            break;
                        case '/':
                            NumStack[++cur1] = num2 / num1;
                            break;
                        default:
                            break;
                        }
                    }
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
                {
                    char chr = OpeStack[cur2];
                    int num1 = NumStack[cur1];
                    int num2 = NumStack[cur1];
                    switch (chr)
                    {
                    case '+':
                        NumStack[++cur1] = num2 + num1;
                        break;
                    case '-':
                        NumStack[++cur1] = num2 - num1;
                        break;
                    case '*':
                        NumStack[++cur1] = num2 * num1;
                        break;
                    case '/':
                        NumStack[++cur1] = num2 / num1;
                        break;
                    default:
                        break;
                    }
                }
                OpeStack[++cur2] = line[i];
            }
            else
            {
                if (cur2 != -1 && OpeStack[cur2] != '(')
                {
                    char chr = OpeStack[cur2];
                    int num1 = NumStack[cur1];
                    int num2 = NumStack[cur1];
                    switch (chr)
                    {
                    case '+':
                        NumStack[++cur1] = num2 + num1;
                        break;
                    case '-':
                        NumStack[++cur1] = num2 - num1;
                        break;
                    case '*':
                        NumStack[++cur1] = num2 * num1;
                        break;
                    case '/':
                        NumStack[++cur1] = num2 / num1;
                        break;
                    default:
                        break;
                    }
                }
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
        switch (chr)
        {
        case '+':
            NumStack[++cur1] = num2 + num1;
            break;
        case '-':
            NumStack[++cur1] = num2 - num1;
            break;
        case '*':
            NumStack[++cur1] = num2 * num1;
            break;
        case '/':
            NumStack[++cur1] = num2 / num1;
            break;
        default:
            break;
        }
    }
    
    int ans = NumStack[0];
    free(NumStack);
    NumStack = NULL;
    free(OpeStack);
    OpeStack = NULL;
    return ans;
}
