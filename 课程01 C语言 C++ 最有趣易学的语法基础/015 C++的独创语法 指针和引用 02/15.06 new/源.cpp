#include<iostream>

using namespace std;

int main()
{
	int x;
	std::cout << "请输入需要分配的内存的大小:";
	std::cin >> x;

	int* p{};
	p = new int{ x };

	delete[] p; //释放分配的空间

	return 0;
}