void QSort(int data[], int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int temp = data[i];

    while (i < j)
    {
        while (i < j && temp < data[j])
            j--;
        if (i < j)
            data[i++] = data[j];
        
        while (i < j && temp >= data[i])
            i++;
        if (i < j)
            data[j--] = data[i];
    }
    data[i] = temp;
    QSort(data, left, i - 1);
    QSort(data, i + 1, right);
}