void QuickSort(int data[], int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int temp = data[i];

	if (i < j)
	{
		while (i < j && temp < data[j])
			j--;
		data[i] = data[j];

		while (i < j && temp >= data[i]);
			i++;
		data[j] = data[i];

		data[i] = temp;
		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
	}
}