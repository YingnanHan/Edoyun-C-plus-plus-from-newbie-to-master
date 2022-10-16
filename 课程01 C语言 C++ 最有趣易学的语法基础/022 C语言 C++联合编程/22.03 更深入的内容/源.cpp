#include<iostream>

using namespace std;

// 从编译器的角度函数就是一个extern得，可以不用附加修饰符
extern int ave(int a, int b); // 声明 多次声明并不影响函数的使用 但是定义只可以有一次

int all; // 定义
extern int all_; // 声明一个变量 专门针对全局变量

// 全局变量有一个固定的地址，这个变量放置在全局变量区

int main()
{
	int c = ave(1, 2);
	std::cout << c << std::endl;
	std::cout << "all_ = " << all_ << std::endl;
	return 0;
}

int pve()
{
	return ave(1, 2); // 使用提前声明的使得两个函数可以互相调用
}

int ave(int a, int b) // 定义
{
	// pve(); // 函数间的互相调用可能会导致栈溢出
	return (a + b) / 2;
}

int all_ = 400; //定义