#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	char inKey{ 'y' };
	while (inKey == 'Y' || inKey == 'y')
	{
		int intIn;
		cout << "请输入一个数:";
		cin >> intIn;
		bool bcase{};
		bcase = (intIn % 2 != 0);
		for (int i = 3; (bcase) && (i <= sqrt(intIn)); i += 2)
		{
			if (intIn % i == 0)
			{
				bcase = true;
				break;
			}
		}
		if (bcase)
		{
			std::cout << "这个数不是质数";
		}
		else
		{
			std::cout << "这个数是质数";
		}
		std::cout << "如果要进行下一次运算请按[Y],按其他任意键退出程序";
		std::cin >> inKey;
	}
}