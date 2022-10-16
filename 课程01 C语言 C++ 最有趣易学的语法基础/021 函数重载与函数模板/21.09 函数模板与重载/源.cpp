#include<iostream>

template<typename type1>
type1 bigger(type1 a, type1 b)
{
	return a > b ? a : b;
}

template<typename T>
T ave(T a, T b, T c)
{
	T x = a * b;
	T p{ 100 };
	return (a + b + c + x) / 3;
}

template<typename T>
T ave(T a, T b)
{
	T x = a * b;
	T p{ 100 };
	return (a + b + x) / 2;
}


template<>
int* bigger(int* a, int* b)
{
	return *a > *b ? a : b;
}

int bigger(int a, int b) // 优先调用非模板函数
{
	return a > b ? a : b;
}

float* bigger(float* a, float* b)
{
	return *a > *b ? a : b;
}

int main()
{
	int a{ 100 }, b{ 200 },d{350};
	int c;
	// c = *bigger(&a, &b); // 若不定义意外 实际按照指针传参数，的话会导致错误，这里面比较的实际上是内存地址
	// c = *bigger(&a, &b); // 完全匹配函数 > 函数重载 > 模板特例 > 一般模板
	c = bigger(a, b);
	std::cout << c;

	return 0;
}
