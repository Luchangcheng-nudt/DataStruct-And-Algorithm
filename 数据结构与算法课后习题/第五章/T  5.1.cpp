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
    for (int i = 1; i < len; ++i)
    {
        int j = i;
        T temp = data[i];
        while (j > 0 && temp < data[j-1])
        {
            data[j] = data[j-1];
            j--;
        }
        data[j] = temp;
        for (int t = 0; t < len; t++)
            cout << data[t] << " ";
        cout << endl;
    }
}
