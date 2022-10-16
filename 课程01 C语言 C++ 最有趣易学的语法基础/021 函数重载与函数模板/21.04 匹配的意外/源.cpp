#include<iostream>

using namespace std;

int ave(int* pa, int count)
{
	return 0;
}

// 这个函数与上面的函数是一样的，不能被称作为函数重载
//int ave(int pa[], int count)
//{
//	return 0;
//}

int ave(int &a, int &b)
{
	std::cout << "ave 两个 int 引用参数";
	return (a + b) / 2;
}

float ave(float a, float b)
{
	std::cout << "ave 两个 float 参数";
	return (a + b) / 2;
}

int ave(int a, int b, int c)
{
	std::cout << "ave 三个 int 参数";
	return (a + b + c) / 3;
}

float ave(float a, float b, float c)
{
	std::cout << "ave 三个 float 参数";
	return (a + b + c) / 3;
}

//int ave(int& a, int& b) // 编译可通过但是实际上在匹配的时候会导致歧义
//{
//	std::cout << "ave 两个 int 参数";
//	return (a + b) / 2;
//}

int main()
{
	int &&a = 100;
	int &&b = 200;

	char aa = 100;
	char bb = 100;

	std::cout << ave(200.0f, 300.0f) << std::endl;
	std::cout << ave(2, 3) << std::endl;
	std::cout << ave(2, 3.4) << std::endl;
	std::cout << ave(2.0f, 3.0f) << std::endl;
	std::cout << ave(aa, bb) << std::endl; // 匹配到了int类型的重载
	std::cout << ave(int(aa), int(bb)) << std::endl; //参数转换过来得到的是临时的变量所以不会调用引用版本

	return 0;
}