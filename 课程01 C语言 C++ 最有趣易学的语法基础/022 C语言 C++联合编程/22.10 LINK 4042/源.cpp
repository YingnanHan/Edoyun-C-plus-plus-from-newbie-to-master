#include<iostream>
#include"math.h"

int main()
{
	// 出现错误的原因是：math.cpp 与 math.c同时编译，最终都生成math.obj文件，会导致
	// 在同一个目录下会有两个同名但是内容不一样的文件，所以会导致连接错误，改正方法是
	// 将其中一个头文件改名
	std::cout << ave(1, 5) << std::endl;
	std::cout << add(1, 5) << std::endl;
	return 0;
}