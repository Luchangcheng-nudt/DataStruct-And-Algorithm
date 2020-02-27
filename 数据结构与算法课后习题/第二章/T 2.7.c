//Programer: Luchangcheng  2019/12/8
//Compiler: gcc version 4.9.2 (x86_64-posix-seh-rev1, Built by MinGW-W64 project)  tested on Ubuntu Kylin 19.10.1
int match(char line[])
{
    int length = strlen(line);
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (line[i] == '(')
            flag = 1;
        if (line[i] == ')')
        {
            if (flag == 1)
                flag = 0;
            else 
                return 0;
        }
    }
    return !flag;
}
