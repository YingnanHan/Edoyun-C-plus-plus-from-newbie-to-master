#include<iostream>
#include"hint.h"

using namespace std;

hint diamonds = 2500;

int main()
{
	while (1)
	{
		std::cout << "��ǰ��ʯ���Ϊ:" << std::ends;
		std::cout << diamonds << std::endl;
		system("pause");
		diamonds = diamonds - 10;
	}
}