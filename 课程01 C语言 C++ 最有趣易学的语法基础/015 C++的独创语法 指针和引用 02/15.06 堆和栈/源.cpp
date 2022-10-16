#include<iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int* d = new int[5];

	// 对的本质其实就是空闲内存，C++中把堆称为自由存储区
	// 只要是你的程序加载后，没有被占用的空闲内存都是自由
	// 存储区,使用new或者malloc申请一块新的内存区域都是有
	// 操作系统在堆上操作
	// 栈是程序在编译时就已经确定了大小的一段内存区域，主
	// 要是用于临时变量的存储，栈的效率要高于堆，但是容量
	// 有限

	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &c << std::endl;
	std::cout << &d << std::endl;
	std::cout << d << std::endl;


	return 0;
}