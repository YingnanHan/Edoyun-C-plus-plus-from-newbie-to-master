#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	char inKey = ' ';
	do
	{
		int intIn;
		std::cout << "������һ����:";
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
			std::cout << "�������һ������";
		}
		else
		{
			std::cout << "���������һ������";
		}
		cout << "���Ҫ������һ�����������밴��[Y],���������˳�:";
		std::cin >> inKey;
	} while (inKey == 'y' || inKey == 'Y');
}