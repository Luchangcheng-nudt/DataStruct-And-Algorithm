void BinaryInsertSort(int data[], int len)
{
    int i = 1;
    for (i; i < len; i++)
    {
        int left = 0;
        int right = i - 1;
        int temp = data[i];
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (temp < data[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }

        int j = i;
        for (j; j > left; j--)
            data[j] = data[j - 1];
        data[j] = temp;
    }
}