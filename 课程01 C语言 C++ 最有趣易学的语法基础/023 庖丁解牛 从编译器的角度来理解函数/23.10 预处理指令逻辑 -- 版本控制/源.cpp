#include<iostream>

using namespace std;

#define VERSION 101
#define SENDMS  1

#if VERSION == 100 // ==号右边是可做简单的计算的
	
	void test()
	{
		cout << "if test";
	}

#elif VERSION == 102

	void test()
	{
		cout << "elif test 1";
	}

#elif VERSION == 103 && SENDMS == 1

	void test()
	{
		cout << "elif test 2";
	}

#else

	void test()
	{
		cout << "else test";
	}

#endif // VERSION == 100

int main()
{
	test();

}