#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int main()
{
	char cIn = _getch();
	if (cIn == '1' || cIn == 'L')
	{
		for (int lv(1); lv <= 100; lv++)
		{
			std::cout << std::setfill(' ');
			std::cout << "\n等级" << std::setw(3) << lv << "           所需经验" << std::setw(10) << lv * lv * 100 << std::endl;
		}
	}

	return 0;
}