#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	char inKey{ 'y' };
	while (inKey == 'Y' || inKey == 'y')
	{
		int intIn;
		cout << "������һ����:";
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
			std::cout << "�������������";
		}
		else
		{
			std::cout << "�����������";
		}
		std::cout << "���Ҫ������һ�������밴[Y],������������˳�����";
		std::cin >> inKey;
	}
}