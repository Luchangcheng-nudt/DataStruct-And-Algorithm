//Programer: Luchangcheng  2019/12/8
//Compiler: gcc version 4.9.2 (x86_64-posix-seh-rev1, Built by MinGW-W64 project)  tested on VSCode  --std=C++11
bool match(char MidString[])
{
	bool hasLeft = false;
	int leftcnt = 0;
	int rightcnt = 0;
	for (int i = 0; i < strlen(MidString); i++)
	{
		if (MidString[i] == ')')
		{
			if (hasLeft == false)
				return false;
			else
			{
				hasLeft = false;
				rightcnt++;
			}
			
		}
		if (MidString[i] == '(')
		{
			hasLeft = true;
			leftcnt++;
		}
	}

	return !hasLeft && leftcnt == 0 && rightcnt == 0;
}
