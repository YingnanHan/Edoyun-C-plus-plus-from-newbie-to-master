#include<iostream>

using namespace std;

template<typename T, short count>
T ave(T(&ary)[count])
{
	T sum = 0;
	for (auto x : ary)
	{
		sum += x;
	}
	return sum / count;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	cout << ave(a); //自动会推断出数组的大小，也就是说count的值会根据a的实际大小推断出来
}