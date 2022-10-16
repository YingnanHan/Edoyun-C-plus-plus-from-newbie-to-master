#include<iostream>

using namespace std;

template<typename T>
T bigger(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
T ave(T a, T b, T c)
{
	T x = a * b;
	T p[100];

	return (a + b + c + x) / 3;
}

int main()
{
	const int a = 100;
	const int b = 12200;
	int c = 100;

	//int c = *bigger(&a, &b); // 这里实际上比较的是内存地址 输出的值是300
	//cout << c;

	const int& la{ a };
	const int& lb{ b };

	c = bigger(la, lb);

	std::cout << la << std::endl;
	std::cout << lb << std::endl;
	std::cout << c << std::endl;

	return 0;
}