#include<iostream>

using namespace std;

int main()
{
	int a{ 500 };
	int b{ 1000 };
	bool c = (a == b); // false true

	std::cout << boolalpha;// 按照英文字母的方式输出布尔变量
	std::cout << c << std::endl;

	bool aa = {}; // 默认使用true来初始化,但如果是空那么就是false
	std::cout << aa << std::endl;

	// 关于收缩转换
	bool bA{ bool(100) };
	int nA{ bA }; // 这个时候bA=1
	std::cout << nA << std::endl;

	return 0;
}