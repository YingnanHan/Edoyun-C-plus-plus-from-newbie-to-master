#include<iostream>

using namespace std;

int main()
{
	char cIn;
	std::cout << "������һ���ַ�:";
	std::cin >> cIn;

	if (cIn > 47)
	{
		if (cIn < 58)
		{
			std::cout << std::endl << "���������һ������:" << cIn << std::endl;
		}
		if (cIn > 64)
		{
			if (cIn < 91)
			{
				std::cout << std::endl << "��������Ǵ�д��ĸ" << cIn << "���Ǹ���ת����Сд:" << char(cIn + 32) << std::endl;
			}
		}
	}
	return 0;
}