#include <iostream>

using namespace std;

int main()
{
	char cIn;
	std::cout << "������һ���ַ�:";
	std::cin >> cIn;

	if (cIn > 47 && cIn < 58)
	{
		std::cout << std::endl << "���������һ������:" << cIn << std::endl;
	}
	if (((cIn >= 65) && (cIn <= 90)) || ((cIn > 96) && (cIn < 123)))
	{
		std::cout << std::endl << "�����������ĸ" << cIn << std::endl;
	}
	return 0;
}
