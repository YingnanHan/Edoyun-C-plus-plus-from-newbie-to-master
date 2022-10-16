


#include<iostream>
#include"hstring.h"
int main()
{
	hstring strAry[100];
	hstring str = "hello";
	strAry[1] = str;

	std::cout << strAry[1][2];
	//
	//str[1] = '2';
	if (str[2111] == hstring::nochar)
	{
		std::cout << "Խ�磡";
	}
	std::cout << str[1000] << std::endl;
	std::cout << str;
}
