#include<iostream>

using namespace std;

int ave(int a, int b)
{
	std::cout << __func__ << std::endl; // __func__ 宏返回其所在的函数名称
	return 0;
}

int main()
{
	std::cout << __func__ << std::endl; // __func__ 宏返回其所在的函数名称
	std::cout << __cplusplus << std::endl; // 清楚知道是不是C语言的源文件,如果不是一个整数文本，那么他就是一个C语言文件
	std::cout << __DATE__ << std::endl; // 获取原文件的编译时间
	std::cout << __TIME__ << std::endl; // 获取原文件的转换单元转化的时间
	std::cout << __FILE__ << std::endl; // 获取转换单元的名字
	ave(0, 1);;
	return 0;
}