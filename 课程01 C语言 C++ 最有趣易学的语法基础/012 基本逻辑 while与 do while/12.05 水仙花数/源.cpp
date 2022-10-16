#include<iostream>

using namespace std;

int main()
{
	int g, s, b;
	for (int i = 100; i < 1000; i++)
	{
		g = i % 10;
		s = i % 100 / 10;
		b = i / 100;
		if (g * g * g + s * s * s + b * b * b == i)
		{
			std::cout << "找到了水仙花数:" << i << std::endl;
		}
	}
	return 0;
}