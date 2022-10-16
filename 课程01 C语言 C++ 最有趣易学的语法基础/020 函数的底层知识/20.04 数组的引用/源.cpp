#include<iostream>

using namespace std;

void size_(int(&art)[100]) //传递一个数组的引用
{
	std::cout << std::endl << sizeof(art);
}

int main()
{
	int a[100];
	int(&b)[100] = a; //b是一个引用了a的数组，中间一定要加上括号
	
	size_(b);
	return 0;
}