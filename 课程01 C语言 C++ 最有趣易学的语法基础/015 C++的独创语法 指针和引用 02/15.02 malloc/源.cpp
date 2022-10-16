#include<iostream>

using namespace std;

int main()
{
	unsigned x;
	std::cin >> x;
	// 输入40
	int* p = (int*)malloc(sizeof(int) * x); // 分配内存 并且使用用户自定义的方式来解释新分配内存的含义

	if (p == nullptr)
	{
		std::cout << "内存分配失败!";
	}
	else
	{
		p[0] = 952;
		p[1] = 953;
		p[2] = p[0] * p[1];

		std::cout << "p[0] = " << p[0] << std::endl;
		std::cout << "p[1] = " << p[1] << std::endl;
		std::cout << "p[2] = " << p[2] << std::endl;
	}
	return 0;
}

