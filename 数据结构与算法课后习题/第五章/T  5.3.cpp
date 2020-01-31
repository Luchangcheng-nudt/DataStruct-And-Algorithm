//Programmer: Luchangcheng  /2020/01/31
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  tested on Ubuntu kylin 19.10.1

#include <iostream>
using namespace std;

template<class T>
void Sort(T data[], int len);

int main()
{
    int data[] = {8, 4, 1, 9, 2, 1, 7, 4};
    Sort(data, 8);
    cout << endl;

    char data0[] = {'V', 'B', 'L', 'A', 'Z', 'Y', 'C', 'H', 'S', 'B', 'H'};
    Sort(data0, 11);
    
    return 0;
}

template<class T>
void Sort(T data[], int len)
{
    for (int tag = len >> 1; tag > 0; tag >>= 1)
    {
        for (int i = tag; i < len; i++)
        {
            int j = i - tag;
            T temp = data[i];

            while (j >= 0 && temp < data[j])
            {
                data[j + tag] = data[j];
                j -= tag;
            }
            data[j + tag] = temp;

            for (int t = 0; t < len; ++t)
                cout << data[t] << " ";
            cout << endl;
        }
    }
}
