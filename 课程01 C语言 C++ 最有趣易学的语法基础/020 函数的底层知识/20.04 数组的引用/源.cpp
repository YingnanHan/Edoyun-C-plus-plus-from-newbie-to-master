#include<iostream>

using namespace std;

void size_(int(&art)[100]) //����һ�����������
{
	std::cout << std::endl << sizeof(art);
}

int main()
{
	int a[100];
	int(&b)[100] = a; //b��һ��������a�����飬�м�һ��Ҫ��������
	
	size_(b);
	return 0;
}