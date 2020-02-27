void PercDown(ElementType data[], int i, int n)
{
    int child = 0;
    ElementType temp = data[i];
    for (i; (i << 1) + 1 < n; i = child)
    {
        child = (i << 1) + 1;
        if (child != n - 1 && data[child] < data[child+1])
            child++;
        if (temp < data[child])
            data[i] = data[child];
        else 
            break;
    }
    data[i] = temp;
}
void HeapSort(ElementType data[], int n)
{
    for (int i = n >> 1; i > -1; i--)
        PercDown(data, i, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&data[0], &data[i]);
        PercDown(data, 0, i);
    }
}