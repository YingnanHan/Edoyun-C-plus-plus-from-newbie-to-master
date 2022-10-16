#include<iostream>
#include"e.h"
using namespace std;

//int ave() // 因为C++对函数会重命名，于是.cpp文件中的函数与同名的.c文件中的函数不会冲突
//{
//	return 1;
//}

int main()
{
	// ave();// 目前的情况是将该函数当做C++函数风格来处理，所以访问不了
	std::cout << ave() << std::endl;
	std::cout << pve() << std::endl;
	return 0;
}