#include<iostream>

using namespace std;

int main()
{
	// 方法一
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (i + j + k == 100 && i * 500 + j * 300 + k * 100 / 3 == 10000)
				{
					std::cout << "高级桌子采购" << i << "张,";
					std::cout << "普通桌子采购" << j << "张,";
					std::cout << "椅子采购" << k << "张,";
					std::cout << std::endl;
				}
			}
		}
	}
	std::cout << "#####################################" << std::endl;
	// 方法二
	int acount = 10000 / 500;
	int bcount = 10000 / 300;
	for (int a = 0; a <= acount; a++)
	{
		for (int b = 0; b < bcount; b++)
		{
			int c = 100 - a - b;
			if (a + b + c == 100 && a * 500 + b * 300 + c * 100 / 3 == 10000)
			{
				std::cout << "高级桌子采购" << a << "张,";
				std::cout << "普通桌子采购" << b << "张,";
				std::cout << "椅子采购" << c << "张,";
				std::cout << std::endl;
			}
		}
	}
	std::cout << "#####################################" << std::endl;
	// 方法三
	acount = 10000 / 500;
	bcount = 10000 / 300;
	for (int a = 0; a <= acount; a++)
	{
		for (int b = 0; b < bcount; b++)
		{
			int c = 100 - a - b;
			if ((c % 3 == 0) && a + b + c == 100 && a * 500 + b * 300 + c * 100 / 3 == 10000)
			{
				std::cout << "高级桌子采购" << a << "张,";
				std::cout << "普通桌子采购" << b << "张,";
				std::cout << "椅子采购" << c << "张,";
				std::cout << std::endl;
			}
		}
	}
	std::cout << "#####################################" << std::endl;
	// 方法四
	for (int num{}; num <= 3; num++)
	{
		std::cout << "高级桌子采购" << num * 4 << "张,";
		std::cout << "普通桌子采购" << 25 - num * 7 << "张,";
		std::cout << "椅子采购" << 75 + 3 * num << "张,";
		std::cout << std::endl;
	}
	return 0;
}