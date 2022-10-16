#include<iostream>

using namespace std;

int main()
{
	for (int i = 4; i < 1000; i++)
	{
		int sum = 0;
		for (int a = 1; a < i; a++)
		{
			if (i % a == 0)
			{
				sum += a;
			}
		}
		if (sum == i)
		{
			std::cout << "找到一个完数:" << i << std::endl;;
		}
	}
	return 0;
}