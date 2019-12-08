#include <iostream>
#include <vector>
using namespace std;

bool match(char MidString[]);
int main()
{
	char midstring[100] = {0};
	cin >> midstring;
	cout << match(midstring);
	return 0;
}

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