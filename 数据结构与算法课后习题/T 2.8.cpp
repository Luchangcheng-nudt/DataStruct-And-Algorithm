//Programer: Luchangcheng  2019/12/7
//Compiler: gcc version 4.9.2 (x86_64-posix-seh-rev1, Built by MinGW-W64 project)  tested on VSCode
#include <iostream>
#define MAXSIZE 100
using namespace std;

template<class T>
struct DStack
{
	T list[MAXSIZE];
	int leftIndex;
	int rightIndex;
	int size;
};

template<class T>
void InitStack(DStack<T>* S);
template<class T>
void Push(DStack<T>* S, int i, T x);
template<class T>
T Pop(DStack<T>* S, int i);

int main()
{
	DStack<int>stk;
	InitStack(&stk);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			Push(&stk, 0, i);
		else
			Push(&stk, 1, i);
	}

	while (stk.leftIndex > -1)
	{
		cout << Pop(&stk, 0) << " ";
	}
	cout << endl;
	while (stk.rightIndex < MAXSIZE)
	{
		cout << Pop(&stk, 1) << " ";
	}
	
	return 0;
}

template<class T>
void InitStack(DStack<T>* S)
{
	for (int i = 0; i < MAXSIZE; i++)
		S->list[i] = 0xffffff;
	S->leftIndex = -1;
	S->rightIndex = MAXSIZE;
	S->size = 0;
}

template<class T>
void Push(DStack<T>* S, int i, T x)
{
	if (S->size + 1 <= MAXSIZE)
	{
		if (i == 0)
		{
			S->list[++S->leftIndex] = x;
			S->size++;
		}
		else
		{
			S->list[--S->rightIndex] = x;
			S->size++;
		}
	}
}

template<class T>
T Pop(DStack<T>* S, int i)
{
	if (S->size > 0)
	{
		if (i == 0 && S->leftIndex > -1)
			return S->list[S->leftIndex--];
		if (i == 1 && S->rightIndex < MAXSIZE)
			return S->list[S->rightIndex++];
	}

	return 0xffffff;
}
