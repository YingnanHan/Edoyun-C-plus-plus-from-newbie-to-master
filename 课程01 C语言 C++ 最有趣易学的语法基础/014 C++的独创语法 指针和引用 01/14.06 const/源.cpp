#include<iostream>

using namespace std;

int main()
{
	/*
	//01
	const int a{ 100 };
	const int b{ 200 };
	int c{ 300 };

	const int* ptr = &a; //指针常量

	ptr = &c; // 不允许修改指针指向常量的的值，但是可以修改指针指向的位置
	// *ptr = 400; //报错

	*/


	/*
	//02
	const int a{ 100 };
	const int b{ 200 };
	int c{ 300 };

	int* const ptr = &a; //常量指针

	ptr = &b; // 允许修改指针指向常量的的值，但是不可以修改指针指向的值
	*ptr = 400; //不报错
	*/

	/*
	// 03
	const int a{ 100 };
	const int b{ 200 };
	int c{ 300 };

	const int* const ptr = &a;

	//ptr = &b; // 不允许修改指针指向常量的的值，不可以修改指针指向的值
	//*ptr = 400; //不报错
	*/


	// 04
	const int a{ 1000 };
	const int b{ 1400 };
	const int* const ptr{ &a };

	int* ptrA{ (int*)&a };
	*ptrA = 9500;
	std::cout << *ptrA << std::endl;
	std::cout << a;

	return 0;
}