#include <iostream>
#include<bitset>

int main()
{
	// 位运算 移位运算符
	int a{ (int)0b11111111011101111111111111111111 }; // 0xFFFFFFFF 带符号的整数值
	std::cout << std::bitset<32>(a) << std::endl; // 输出原数字

	a <<= 8; // a = a << 8
	std::cout << std::bitset<32>(a) << std::endl; // 输出左移8bit后的结果

	unsigned b{ (unsigned)a }; // 左侧补充1
	b >>= 7; // 输出右移7bit后的结果
	std::cout << std::bitset<32>(b) << std::endl;

	a >>= 7; // 输出右移7bit后的结果
	std::cout << std::bitset<32>(a) << std::endl;

	int c{ -100 }; // 正数补充0 负数补充1
	c >>= 2;
	std::cout << std::bitset<32>(c) << std::endl;

	std::cout << "===================================" << std::endl;
	// 位运算 取反运算符
	int test{ 0xffff };
	std::cout << std::bitset<32>(test) << std::endl;
	test = ~test;
	std::cout << std::bitset<32>(test) << std::endl;

	// 位运算 与运算符
	int test1 = 0x2800; //取出前两位
	std::cout << std::bitset<32>(test1) << std::endl;
	test1 = test1 & 0xFFFF >> 8;
	std::cout << std::bitset<32>(test1) << std::endl;

	return 0;
}