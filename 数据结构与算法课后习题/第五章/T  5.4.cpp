//Programmer: Luchangcheng  2020/01/31
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)   tested on Ubuntu Kylin  19.10.1

#include <iostream>
using namespace std;

template<class T>
void Sort(T data[], int len);

int main()
{
    int data[] = {85, 40, 10, 95, 20, 15, 70, 45, 40, 90, 80, 10};
    Sort(data, 12);
    
    return 0;
}

template<class T>
void Sort(T data[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[i] < data[j])
            {
                swap(data[i], data[j]);
                for (int i = 0; i < len; i++)
                    cout << data[i] << " ";
                cout << endl;
            }
        }   
    }
}
