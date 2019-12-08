//Programer: Luchangcheng  2019/12/8
//Compiler: gcc version 4.9.2 (x86_64-posix-seh-rev1, Built by MinGW-W64 project)  tested on VSCode  --std = C++11
#include <vector>
bool isPalindrome(vector<char>& Vector)
{
	int size = Vector.size();
	for (int i = 0; i < size / 2; i++)
	{
		if (Vector[i] != Vector[size - i - 1])
			return false;
	}
	return true;
}
