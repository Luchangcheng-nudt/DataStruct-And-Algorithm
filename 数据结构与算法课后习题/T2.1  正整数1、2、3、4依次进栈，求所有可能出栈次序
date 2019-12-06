//Programmer: Luchangcheng  2019/12/6
//Compiler: MSVC14.23  tested on Visual Studio Community 2019
#include <iostream>
#include <stack>
using namespace std;

void BinarySearchTree(int step, stack<int> spnd, string ans);
int main()
{
	int step = 1;
	stack<int>temp;
	temp.push(1);
	string ans = "";
	BinarySearchTree(1, temp, ans);
	return 0;
}

void BinarySearchTree(int step, stack<int> spnd, string ans)
{
	if (step == 4)
	{
		while (!spnd.empty())
		{
			ans += spnd.top() + '0';
			ans += " ";
			spnd.pop();
		}
		ans.pop_back();
		cout << ans << endl;
		return;
	}

	spnd.push(step + 1);
	BinarySearchTree(step + 1, spnd, ans);
	spnd.pop();

	if (!spnd.empty())
	{
		ans += spnd.top() + '0';
		ans += " ";
		spnd.pop();
		BinarySearchTree(step, spnd, ans);
	}
}
