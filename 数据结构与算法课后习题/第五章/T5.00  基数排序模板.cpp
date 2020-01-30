//Programmer: Luchangcheng  2020/1/30
//Compiler: MSVC14.23  tested on Windows 10
void BasisSort(int data[], int len)
{
	vector<queue<int> >box(10);
	vector<queue<int> >preBox = box;

	int maxnum = 0;
	for (int i = 0; i < len; ++i)
	{
		if (data[i] > maxnum)
			maxnum = data[i];
	}

	int maxlength = 0;
	while (maxnum > 0)
	{
		++maxlength;
		maxnum /= 10;
	}

	bool isBegin = true;
	int index = 1;
	while (maxlength > 0)
	{
		if (isBegin == true)
		{
			for (int i = 0; i < len; i++)
				box[(data[i] / index) % 10].push(data[i]);
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				while (!preBox[i].empty())
				{
					box[(preBox[i].front() / index) % 10].push(preBox[i].front());
					preBox[i].pop();
				}
			}
		}

		--maxlength;
		index *= 10;
		preBox = box;
		for (int i = 0; i < 10; ++i)
			box[i] = queue<int>();
		isBegin = false;
	}

	index = 0;
	for (int i = 0; i < 10; i++)
	{
		while (!preBox[i].empty())
		{
			data[index++] = preBox[i].front();
			preBox[i].pop();
		}
	}
}
