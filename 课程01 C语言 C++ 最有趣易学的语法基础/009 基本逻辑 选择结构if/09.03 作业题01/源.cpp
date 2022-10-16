#include<iostream>

using namespace std;

int main()
{
	char cIn;
	std::cout << "请输入一个字符:";
	std::cin >> cIn;

	if (cIn > 47)
	{
		if (cIn < 58)
		{
			std::cout << std::endl << "您输入的是一个数字:" << cIn << std::endl;
		}
		if (cIn > 64)
		{
			if (cIn < 91)
			{
				std::cout << std::endl << "您输入的是大写字母" << cIn << "我们给他转换成小写:" << char(cIn + 32) << std::endl;
			}
		}
	}
	return 0;
}