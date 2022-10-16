#include<iostream>

using namespace std;

//int ave() // 因为C++对函数会重命名，于是.cpp文件中的函数与同名的.c文件中的函数不会冲突
//{
//	return 1;
//}

extern "C"
{
	#include"e.h" // 表示头文件的内容就是C风格的
}

extern "C" int xve() // 在cpp文件中变通的使用C语言风格xve函数
{
	return 3;
}

int main()
{
	// ave();// 目前的情况是将该函数当做C++函数风格来处理，所以访问不了
	std::cout << ave() << std::endl;
	std::cout << pve() << std::endl;
	return 0;
}