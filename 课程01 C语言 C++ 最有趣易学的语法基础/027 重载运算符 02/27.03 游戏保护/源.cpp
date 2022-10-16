#include<iostream>
#include"hint.h"

using namespace std;

hint diamonds = 2500;

int main()
{
	while (1)
	{
		std::cout << "当前钻石余额为:" << std::ends;
		std::cout << diamonds << std::endl;
		system("pause");
		diamonds = diamonds - 10;
	}
}