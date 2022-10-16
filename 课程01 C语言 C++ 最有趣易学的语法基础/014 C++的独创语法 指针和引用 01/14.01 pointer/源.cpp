#include<iostream>

using namespace std;

int main()
{
	// int* a1, b1; // b1是指针
	// int *a2, b2; // b2是变量

	int a{ 5000 };
	int* pa{ &a }; // 变量类型要对应

	// pa = 0x5000;
	//PA = A的内存地址
	//*PA 读写A的内存空间

	std::cout << "内存地址：" << pa << "\na = " << a;
	std::cout << std::endl;
	*pa = 6666; //直接操作内存空间，修改指向目标的值
	std::cout << "内存地址：" << pa << "\na = " << a;
	(*pa)++;
	std::cout << std::endl;
	std::cout << "内存地址：" << pa << "\na = " << a;

	return 0;
}