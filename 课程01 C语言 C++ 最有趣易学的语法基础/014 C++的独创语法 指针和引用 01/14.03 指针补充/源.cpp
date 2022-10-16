#include<iostream>

using namespace std;

int main()
{
	// x86系统是32bit
	// x64系统是64bit
	// 不同类型的指针和变量地址不可以随意直接赋值
	int* ptr1{};
	std::cout << "int指针的大小为:\t" << sizeof(ptr1) << std::endl;
	char* ptr2{};
	std::cout << "char指针的大小为:\t" << sizeof(ptr2) << std::endl;

	///////////////////////////////////////////////////////////////

	unsigned ua{ 99901 };
	int       a{ 9999 };

	int* ptr(&a);
	ptr = (int*)&ua;	// 对指针类型进行强制转换
	long long* uptr{ (long long*)&ua };
	ptr = (int*)&ua;

	std::cout << sizeof(ptr) << std::endl;
	char* ctr{};

	*ptr = -1;

	ctr = (char*)ptr;

	*ctr = 'A';

	std::cout << sizeof(ctr) << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << *uptr << std::endl;

	return 0;
}