//Programmer: Luchangcheng  2020/2/13
//Compiler: MSVC 14.23  tested on Windows 10
void MergeSort(int data[], int left, int right)
{
	if (left < right - 1)
	{
		int mid = (left + right) >> 1;
		MergeSort(data, left, mid);
		MergeSort(data, mid, right);
		Merge(data, left, mid, right);
	}
}

void Merge(int data[], int left, int mid, int right)
{
	int* list = (int*)malloc((right - left) * sizeof(int));
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
	
	free(list);
	list = NULL;
}
