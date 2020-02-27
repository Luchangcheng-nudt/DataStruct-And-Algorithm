int match(char s[])
{
    char stack[128] = {0};
    int cur = -1;
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(')
            stack[++cur] = s[i];
        if (s[i] == ')')
        {
            if (cur != -1 && stack[cur] == '(')
                stack[cur--] = 0;
            else 
                return 0;
        }
    }

    return cur == -1;
}
