#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	char inKey = ' ';
	do
	{
		int intIn;
		std::cout << "请输入一个数:";
		std::cin >> intIn;
		bool bcase{};
		bcase = (intIn % 2 != 0);
		for (int i = 3; bcase && (i <= sqrt(intIn)); i += 2)
		{
			if (intIn % i == 0)
			{
				bcase = false;
				break;
			}
		}
		if (bcase)
		{
			std::cout << "这个数是一个素数";
		}
		else
		{
			std::cout << "这个数不是一个素数";
		}
		cout << "如果要进行下一次输入运算请按下[Y],按其他键退出:";
		std::cin >> inKey;
	} while (inKey == 'y' || inKey == 'Y');
}