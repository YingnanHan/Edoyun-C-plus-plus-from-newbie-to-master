#include<iostream>

inline int ave(int x) // ����������Ҫʹ�õݹ�
{
	if (x == 1)
	{
		return 1;
	}
	return x * ave(x - 1);
}

int main()
{
	std::cout << ave(10);
	return 0;
}