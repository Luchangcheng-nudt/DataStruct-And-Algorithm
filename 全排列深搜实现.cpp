//Program by Luchangcheng 2019/12/2
//Compiler: clang version 9.0.0 (tags/RELEASE_900/final)  tested on VSCode
#include <iostream>
using namespace std;

void allSort(int arr[], int step, int size, int list[], bool book[]);
int main()
{
    int n;
    cin >> n;

    int *nums = new int[n];
    int *list = new int[n];
    bool *book = new bool[n];

    for (int i = 0; i < n; i++)
        list[i] = book[i] = 0;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    allSort(nums, 0, n, list, book);
    delete[] nums;
    delete[] list;
    delete[] book;
    return 0;
}

void allSort(int arr[], int step, int size, int list[], bool book[])
{
    if (step == size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (!book[i])
        {
            list[step] = arr[i];
            book[i] = true;
            allSort(arr, step + 1, size, list, book);
            book[i] = false;
        }
    }
}
