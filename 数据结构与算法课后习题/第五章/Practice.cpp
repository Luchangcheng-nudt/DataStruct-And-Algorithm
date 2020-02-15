//Programmer: Luchangcheng  2020/02/15
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  tested on Ubuntu Kylin 19.10.1
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
void ShellSort(T data[], int len);
template <class T>
void DirectInsertSort(T data[], int len);
template <class T>
void HalfInsertSort(T data[], int len);
template <class T>
void DirectSelectSort(T data[], int len);
template <class T>
void QuickSort(T data[], int left, int right);
template <class T>
void MergeSort(T data[], int left, int right);
template <class T>
void Merge(T data[], int left, int mid, int right);

int main()
{
    int list1[] = {8, 4, 1, 9, 2, 1, 7, 4};
    char list2[] = "VBLAZYCHSBH";
    MergeSort(list1, 0, 8);
    
    for (const auto& ptr : list1)
        cout << ptr << " ";
    cout << endl;

    return 0;
}

template <class T>
void ShellSort(T data[], int len)
{
    for (int tag = len >> 1; tag > 0; tag >>= 1)
    {
        for (int i = tag; i < len; i++)
        {
            T temp = data[i];
            int j = i - tag;

            while (j >= 0 && temp < data[j])
            {
                data[j + tag] = data[j];
                j -= tag;
            }

            data[j + tag] = temp;
        }
    }
}

template<class T>
void DirectInsertSort(T data[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        T temp = data[i];
        while (j >= 0 && temp < data[j])
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

template<class T>
void HalfInsertSort(T data[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int m = 0;
        int n = i - 1;
        T temp = data[i];
        while (m <= n)
        {
            int mid = (m + n) >> 1;
            if (data[mid] < temp)
                m = mid + 1;
            else 
                n = mid - 1;
        }
        for (int j = i; j > m; j--)
            data[j] = data[j-1];
        data[m] = temp;
    }
}

template <class T>
void DirectSelectSort(T data[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < len; j++)
        {
            if (data[j] < data[k])
                k = j;
        }
        if (i != k)
        {
            T temp = data[i];
            data[i] = data[k];
            data[k] = temp;
        }
    }
}

template<class T>
void QuickSort(T data[], int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        T basis = data[i];

        while (i < j)
        {
            while (i < j && data[j] > basis)
                j--;
            if (i < j)
                data[i++] = data[j];

            while (i < j && data[i] <= basis)
                i++;
            if (i < j)
                data[j--] = data[i];
        }
        data[i] = basis;

        QuickSort(data, i + 1, right);
        QuickSort(data, left, i - 1);
    }
}

template <class T>
void MergeSort(T data[], int left, int right)
{
    if (left < right - 1)
    {
        int mid = (left + right) >> 1;
        MergeSort(data, mid, right);
        MergeSort(data, left, mid);
        Merge(data, left, mid, right);
    }
}

template <class T>
void Merge(T data[], int left, int mid, int right)
{
    int* list = new int[right - left];
    int i = left;
    int j = mid;
    int t = 0;

    while (i < mid && j < right)
        list[t++] = data[i] < data[j] ? data[i++] : data[j++];
    while (i < mid)
        list[t++] = data[i++];
    while (j < right)
        list[t++] = data[j++];
    
    for (i = 0; i < t; i++)
        data[left++] = list[i];
    delete[] list;
}
