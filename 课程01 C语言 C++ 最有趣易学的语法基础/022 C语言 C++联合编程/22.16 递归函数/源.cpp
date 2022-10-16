#include<iostream>

inline int ave(int x) // 内联函数不要使用递归
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