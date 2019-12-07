//Programmer: Luchangcheng  2019/12/6
//Compiler: MSVC14.23  tested on Visual Studio 2019   --std = C++17
//题目：编写将线性表原地置逆的算法，空间开销为O(1)
template<class T>
void reverseVector(vector<T>& list, int n)
{
	if (list.size() < n)
		return;

	int i = 0;
	for (int i = 0; i < n / 2; i++)
	{
		int temp = list[i];
		list[i] = list[n - 1 - i];
		list[n - 1 - i] = temp;
	}
}
