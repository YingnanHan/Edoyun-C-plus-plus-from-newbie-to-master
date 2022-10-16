#include<iostream>

using namespace std;
// Ωµ–Ú≈≈–Ú
template<typename T>
void Swap(T& a, T& b)
{
	T tmp{ a };
	a = b;
	b = tmp;
}

template<typename T>
void Sort(T* ary, unsigned count, bool BigSort = true)
{
	for (unsigned i = 0; i < count; i++)
	{
		for (int i = 1; i < count; i++)
		{
			bool bcase = BigSort ? ary[i] > ary[i - 1] : ary[i] > ary[i - 1];
			if (bcase)
			{
				Swap(ary[i], ary[i - 1]);
			}
		}
	}
}

int main()
{
	int a[6]{ 123, 456, 789, 10 ,20, 3453 };
	string s[6]{ "123", "345", "1232", "222", "2222" };
	Sort(a, 6);
	for (auto x : a)
	{
		cout << x << " ";
	}
	cout << endl;

	Sort(s, 6);
	for (auto x : s)
	{
		cout << x << " ";
	}
	cout << endl;
	return 0;
}