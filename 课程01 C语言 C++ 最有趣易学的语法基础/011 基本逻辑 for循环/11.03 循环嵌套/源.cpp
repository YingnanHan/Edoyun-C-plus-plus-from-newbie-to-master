#include<iostream>
#include<conio.h>
#include<iomanip>

int main()
{
	std::cout << std::setfill(' ');
	for (int y{}; y < 10; y++)
	{
		for (int x{}; x < 10; x++)
		{
			if (x == 0 || y == 0 || y < x)
			{
				continue;
			}

			std::cout << std::setw(3) << x * y << " ";
		}
		std::cout << std::endl;
	}
lexit:
	std::cout << "不想打印了" << std::endl;
	return 0;
}