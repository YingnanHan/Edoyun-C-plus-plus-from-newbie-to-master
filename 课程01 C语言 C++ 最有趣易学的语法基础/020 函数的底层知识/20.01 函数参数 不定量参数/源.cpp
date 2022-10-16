// 可变参数函数 求解平均数

#include<iostream>
#include<cstdarg>

using namespace std;

struct SArg
{
	int count;//参数的个数
	char* cMem; //仅仅保存一个内存地址
};

int Average(int count, ...) // 参数是被放在一块连续的地址空间的
{
	va_list arg; // va_list == char* 如何读取数据取决于地址与内存类型
	va_start(arg, count); // 将arg中所传递的数据按照count所指定的大小，将可变参数传递至arg
	// va_arg(arg, int); // 读取可变参数列表中的数据
	int sum{};
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg); //释放arg资源
	sum /= count;
	return sum;
}

int Ave(SArg& y)
{
	int sum{};
	int* ary = (int*)y.cMem;
	for (int i = 0; i < y.count; i++)
	{
		sum += ary[i];
	}
	return sum /= y.count;
}

void main()
{
	// ①
	int x = Average(5, 6, 67, 2, 78, 87, 32.3,2);
	std::cout << "平均数:" << x;

	// ②
	SArg y;
	y.count = 5;
	y.cMem = (char*)new int[5] {562,(int)321.23f,256,541,120}; // 传递给左侧的是一个指针

	// ③
	x = Ave(y);
	std::cout << "平均数:" << x;
}