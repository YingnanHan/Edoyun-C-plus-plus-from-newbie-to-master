#include"hstring.h"
#include<iostream>

using namespace std;

int main()
{
	hstring str{ "-1" }; //切记不要越界
	str = str + 123;
	int x = (int)str;
	std::cout << x;
}