#include<iostream>

using namespace std;

int main()
{

	int a[]{ 1001, 1002, 1003, 1004 };
	int* ptr{ &a[0] };

	std::cout << ptr << std::endl;

	ptr = ptr - 1; // 减去一个类型所占字节大小

	std::cout << a[0] << std::endl;

	std::cout << ptr << std::endl;
	std::cout << &a[1] << std::endl;
	// 指针+1的时候 数值变化量是 +1*指针对应数据类型的大小
	std::cout << *ptr << std::endl;

	return 0;
}