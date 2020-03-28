void MergeSort(ElementType data[], int n)
{
	int i = 1;
	ElementType *ans = (ElementType*)malloc(n * sizeof(ElementType));

	while (i < n)
	{
		OnePassMerge(ans, data, i, n);
		i <<= 1;

		if (i < n)
			OnePassMerge(data, ans, i, n);
		else 
			memcpy(data, ans, n * sizeof(ElementType));
	}
	free(ans);
}
void OnePassMerge(ElementType Dst[], ElementType Src[], int len, int n)
{
	int i = 0;
	for (i; i < n - (len << 1); i += (len << 1))
		TwoPassMerge(Dst, Src, i, i + len, i + (len << 1));

	if (i < n - len)
		TwoPassMerge(Dst, Src, i, i + len, n);
	else
		memcpy(&Dst[i], &Src[i], (n - i) * sizeof(ElementType));
}
void TwoPassMerge(ElementType Dst[], ElementType Src[], int low, int mid, int high)
{
	int i = low;
	int j = mid;
	for (i, j; i < mid && j < high;)
		Dst[low++] = Src[i] < Src[j] ? Src[i++] : Src[j++];
	
	if (i < mid)
		memcpy(&Dst[low], &Src[i], (mid - i) * sizeof(ElementType));
	if (j < high)
		memcpy(&Dst[low], &Src[j], (high - mid) * sizeof(ElementType));
}