#include<iostream>

using namespace std;

int main()
{
	// ����һ
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (i + j + k == 100 && i * 500 + j * 300 + k * 100 / 3 == 10000)
				{
					std::cout << "�߼����Ӳɹ�" << i << "��,";
					std::cout << "��ͨ���Ӳɹ�" << j << "��,";
					std::cout << "���Ӳɹ�" << k << "��,";
					std::cout << std::endl;
				}
			}
		}
	}
	std::cout << "#####################################" << std::endl;
	// ������
	int acount = 10000 / 500;
	int bcount = 10000 / 300;
	for (int a = 0; a <= acount; a++)
	{
		for (int b = 0; b < bcount; b++)
		{
			int c = 100 - a - b;
			if (a + b + c == 100 && a * 500 + b * 300 + c * 100 / 3 == 10000)
			{
				std::cout << "�߼����Ӳɹ�" << a << "��,";
				std::cout << "��ͨ���Ӳɹ�" << b << "��,";
				std::cout << "���Ӳɹ�" << c << "��,";
				std::cout << std::endl;
			}
		}
	}
	std::cout << "#####################################" << std::endl;
	// ������
	acount = 10000 / 500;
	bcount = 10000 / 300;
	for (int a = 0; a <= acount; a++)
	{
		for (int b = 0; b < bcount; b++)
		{
			int c = 100 - a - b;
			if ((c % 3 == 0) && a + b + c == 100 && a * 500 + b * 300 + c * 100 / 3 == 10000)
			{
				std::cout << "�߼����Ӳɹ�" << a << "��,";
				std::cout << "��ͨ���Ӳɹ�" << b << "��,";
				std::cout << "���Ӳɹ�" << c << "��,";
				std::cout << std::endl;
			}
		}
	}
	std::cout << "#####################################" << std::endl;
	// ������
	for (int num{}; num <= 3; num++)
	{
		std::cout << "�߼����Ӳɹ�" << num * 4 << "��,";
		std::cout << "��ͨ���Ӳɹ�" << 25 - num * 7 << "��,";
		std::cout << "���Ӳɹ�" << 75 + 3 * num << "��,";
		std::cout << std::endl;
	}
	return 0;
}