#include<iostream>

/*  // v1
void Sort(int ary[], unsigned count, bool BigSort)
{
	for (int i = 1; i < count; i++)
	{
		for (int i = 1; i < count; i++)
		{
			if (BigSort)
			{
				if (ary[i] > ary[i - 1]) // 由大到小
				{
					int tmp = ary[i];
					ary[i] = ary[i - 1];
					ary[i - 1] = tmp;
				}
			}
			else
			{
				if (ary[i] < ary[i - 1]) // 由小到大
				{
					int tmp = ary[i];
					ary[i] = ary[i - 1];
					ary[i - 1] = tmp;
				}
			}	
		}
	}
}
*/

// v2
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// 默认参数只能放在最后
void Sort(int ary[], unsigned count, bool BigSort=true)
{
	for(int i = 1; i < count; i++)
	{
		for (int i = 1; i < count; i++)
		{
			bool bcase = BigSort ? ary[i] > ary[i - 1] : ary[i] < ary[i - 1];
			if (bcase)
			{
				Swap(ary[i], ary[i - 1]);
			}
		}
	}
}

int main()
{
	int a[5]{2302, 5212, 3654, 9740, 5200};
	Sort(a, 5, false);
	for (auto x : a)
	{
		std::cout << x << std::endl;
	}
}