#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map<char, int>code;
	code['+'] = code['-'] = 1;
	code['*'] = code['/'] = 2;
	string mid;
	cin >> mid;
	stack<char>s;
	vector<string>ans;

	int i = 0;
	if (mid[i] == '+' || mid[i] == '-')
	{
		string temp = "";
		temp += mid[i];
		while ('0' <= mid[++i] && mid[i] <= '9')
			temp += mid[i];
		ans.push_back(temp);
	}
	for (i; i < mid.length();)
	{
		if ('0' <= mid[i] && mid[i] <= '9')
		{
			string temp = "";
			while ('0' <= mid[i] && mid[i] <= '9' || mid[i] == '.')
			{
				temp += mid[i];
				i++;
			}
			ans.push_back(temp);
		}
		else
		{
			if (mid[i] == '(')
			{
				s.push(mid[i]);
				i++;
			}
			else if (mid[i] == ')')
			{
				while (s.top() != '(')
				{
					string temp = "";
					temp += s.top();
					ans.push_back(temp);
					s.pop();
				}
				s.pop();
				i++;
			}
			else
			{
				if ((mid[i] == '-') && !('0' <= mid[i - 1] && mid[i - 1] <= '9'))
				{
					string temp = "-";
					i++;
					while ('0' <= mid[i] && mid[i] <= '9' || mid[i] == '.')
					{
						temp += mid[i];
						i++;
					}
					ans.push_back(temp);
				}
				else
				{
					while (!s.empty() && code[mid[i]] <= code[s.top()])
					{
						string temp = "";
						temp += s.top();
						ans.push_back(temp);
						s.pop();
					}
					s.push(mid[i]);
					i++;
				}
			}
		}
	}

	while (!s.empty())
	{
		string temp = "";
		temp += s.top();
		s.pop();
		ans.push_back(temp);
	}

	int size = ans.size();
	for (i = 0; i < size - 1; i++)
		cout << ans[i] << " ";
	cout << ans[size - 1];

	return 0;
}