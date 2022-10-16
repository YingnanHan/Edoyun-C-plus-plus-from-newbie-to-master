#include<iostream>

using namespace std;

int main()
{
	// 通过反汇编的方式来研究i++与++i
	int a{ 10 };
	a++;
	++a;

	int b{ 5 };
	int c{};

	c = b + a++;
	c = b + ++a;

	c = 3 * -b++ + a;
	std::cout << c << std::endl;
	c = 2 * -b-- - a;
	std::cout << c << std::endl;

	return 0;
}