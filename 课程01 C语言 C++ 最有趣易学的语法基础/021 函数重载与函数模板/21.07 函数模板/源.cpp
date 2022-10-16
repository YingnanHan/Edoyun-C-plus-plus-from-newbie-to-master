#include<iostream>

template<typename T>
T ave(T a, T b, T c)
{
	return (a + b + c) / 3;
}

int main()
{
	int a{ 100 }, b{ 200 }, c{ 300 };
	// c = *ave(&a, &b, &c); // 指针在函数模板中的错误用法
	// 人工设定实际的参数类型 如果不进行设定 那么就会有编译器自行推断
	std::cout << ave<float>(12.0f, 23.9f, 2.0f) << std::endl;
	std::cout << ave<int>(12, 23, 2) << std::endl;
	std::cout << (char)ave<char>((char)11, char(12), char(13)) << std::endl;
	return 0;
}