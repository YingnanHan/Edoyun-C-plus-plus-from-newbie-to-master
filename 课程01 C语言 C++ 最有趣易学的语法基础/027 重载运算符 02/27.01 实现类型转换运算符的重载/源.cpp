#include"hstring.h"
#include<iostream>

using namespace std;

int main()
{
	hstring str{ "-1" }; //�мǲ�ҪԽ��
	str = str + 123;
	int x = (int)str;
	std::cout << x;
}