#include<iostream>
#include"hstring.h"

using namespace std;

class T
{
public:
	explicit T(int val)
	{

	}
	explicit operator int()
	{
		return 1;
	}
	int operator+(T x)
	{
		return 2;
	}
};

int main()
{
	// part01

	//T t1{100}, t2{200};
	//int x = t1 + T(100); // 强制类型转化
	//cout << x;

	// part02

	/*hstring str;
	str = str + 123;
	std::cout << str;
	while (1);*/


	// part03

	//hstring str(-123);
	//// std::cout << str;

	////str = str + 123;
	//
	//int a = 500;
	//a + 200;
	//// str = "123"; // 123123 123+123
	//str + 123;

	//std::cout << str + 123;

	//// int x = (int)(str + 123); // 123 hstring("123") int+123 hstring(123)
	//cout << a;
	//while (1);


	// part 04

	hstring strls{ (char)0 };

	if (strls == nullptr) std::cout << "空字符串!";
	else std::cout << "非空字符串!";

	return 0;
}