#include<iostream>

using namespace std;

/*
未定义行为就是我们在编写代码的过程中，C++标准委员会未定义的行为，未定义行为的结果是不确定的
具体在不同的编译器中下会有不同的效果；比如
*/

int main()
{
	int a = 1;
	int b = 2;
	int c = 0;

	{
		c = 2 * a++ + ++a * 6;
	}

	int x = -25602;

	{
		x = x >> 2;
	}

	return 0;
}