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

int bigger(int a, int b) // ���ȵ��÷�ģ�庯��
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
	// c = *bigger(&a, &b); // ������������ ʵ�ʰ���ָ�봫�������Ļ��ᵼ�´���������Ƚϵ�ʵ�������ڴ��ַ
	// c = *bigger(&a, &b); // ��ȫƥ�亯�� > �������� > ģ������ > һ��ģ��
	c = bigger(a, b);
	std::cout << c;

	return 0;
}
