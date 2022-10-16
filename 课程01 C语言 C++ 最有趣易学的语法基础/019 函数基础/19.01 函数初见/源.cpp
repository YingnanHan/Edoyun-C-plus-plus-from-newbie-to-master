#include<iostream>

using namespace std;

int Add(int a, int b)
{
	return a * 100 + b * 100;
}

void PrintEnding(const char* str, int x)
{
	std::cout << str << x << std::endl;
}

int main()
{
	int x{ Add(1,2)};
	PrintEnding("生命值:", x);

	x = Add(3, 4);
	PrintEnding("魔法值:", x);

	return 0;
} 