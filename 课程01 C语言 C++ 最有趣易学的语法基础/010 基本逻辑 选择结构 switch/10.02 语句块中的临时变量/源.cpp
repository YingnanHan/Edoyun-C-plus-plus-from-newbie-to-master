#include<iostream>

using namespace std;

int main()
{
	if (int a, b, c; true) // C++17新语法
	{
		a = 1;
		b = 2;
		c = 3;
	}
	else
	{
		a = 3;
		b = 2;
		c = 1;
	}

	switch (2)
	{
	case 2:
	{
		int a = 5;
	}
	case 3:
		// 这里不可以使用a
		break;
	}

	switch (int a = 0; 2) // int a=0; 删除后会报错
	{
	case 2:
	{
		a = 5;
	}
	case 3:
		// 可以使用a C++17新语法
		cout << a;
		break;
	}
	return 0;
}