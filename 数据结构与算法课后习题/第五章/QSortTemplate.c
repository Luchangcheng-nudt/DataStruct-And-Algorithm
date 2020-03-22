template<class T>
void QuickSort(T list[], int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        T basis = list[i];

        while (i < j)
        {
            while (i < j && list[j] >= basis)
                j--;
            list[i] = list[j];

            while (i < j && list[i] <= basis)
                i++;
            list[j] = list[i];
        }
        list[i] = basis;

        QuickSort(list, i + 1, right);
        QuickSort(list, left, i - 1);
    }
}
