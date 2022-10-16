#include<iostream>
#include"hint.h"

using namespace std;

int main()
{
	hint hp = { 250 };
	std::cout << "HP=" << hp--;
	int x = hp-- + 200;
	std::cout << std::endl << x << std::endl;

	hint mp = { 250 };
	std::cout << "MP=" << --mp;
	int y = ++mp + 200;
	std::cout << std::endl << y << std::endl;

	return 0;
}