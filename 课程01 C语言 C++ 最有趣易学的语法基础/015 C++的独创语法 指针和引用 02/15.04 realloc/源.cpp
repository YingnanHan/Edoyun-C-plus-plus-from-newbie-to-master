#include<iostream>

using namespace std;

int main()
{
	unsigned x;
	std::cout << "请输入需要分配的内存的大小:";
	std::cin >> x;
	int* pc{};
	int* pm{};
	int* bm{}; // 用于备份

	pm = (int*)malloc(sizeof(int) * x);// 返回void*类型 然后强制转换 初始化内存中元素随机
	pc = (int*)calloc(x, sizeof(int)); // 返回void*类型 然后强制转换 初始化内存中元素为零

	std::cout << pm[0] << std::endl;
	std::cout << pc[0] << std::endl;

	if (pc == nullptr)
	{
		std::cout << "内存分配失败" << std::endl;
	}
	else
	{
		pm[0] = 952;
		pm[1] = 953;
		pm[2] = pm[0] * pm[1];
		std::cout << pm[0] << " " << pm[1] << " " << pm[2] << std::endl;
	}

	std::cout << "请重新输入需要分别配的内存大小:";
	std::cin >> x;
	bm = pm;
	pm = (int*)realloc(pm, x);
	std::cout << pm << "=========" << bm << std::endl; // realloc前后地址的变化情况
	// 这块与内存页面有关

	return 0;
}