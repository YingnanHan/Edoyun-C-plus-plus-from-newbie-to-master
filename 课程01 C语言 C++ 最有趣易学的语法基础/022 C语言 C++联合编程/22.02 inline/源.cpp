#include<iostream>

using namespace std;

//// 局部静态变量和全局变量的生命周期是一样的
//int ave(int a, int b)
//{
//	static int count{ 200 }; // 变量count之后会初始化一次，不会因为函数的重新调用而重新初始化
//	std::cout << count++ << std::endl;
//	return (a + b) / 2;
//}

inline int add(int a, int b) // 编译器自动优化函数
{
	return a + b;
}

int main()
{
	// 01
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);

	// 02
	std::cout << add(1, 1); // 编译器只有对少代码的函数使用inline才有效果

	return 0;
}