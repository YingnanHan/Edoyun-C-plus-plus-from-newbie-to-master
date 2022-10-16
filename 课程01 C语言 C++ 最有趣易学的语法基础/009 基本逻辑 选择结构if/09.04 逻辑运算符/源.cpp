#include <iostream>

using namespace std;

int main()
{
	char cIn;
	std::cout << "请输入一个字符:";
	std::cin >> cIn;

	if (cIn > 47 && cIn < 58)
	{
		std::cout << std::endl << "您输入的是一个数字:" << cIn << std::endl;
	}
	if (((cIn >= 65) && (cIn <= 90)) || ((cIn > 96) && (cIn < 123)))
	{
		std::cout << std::endl << "您输入的是字母" << cIn << std::endl;
	}
	return 0;
}
