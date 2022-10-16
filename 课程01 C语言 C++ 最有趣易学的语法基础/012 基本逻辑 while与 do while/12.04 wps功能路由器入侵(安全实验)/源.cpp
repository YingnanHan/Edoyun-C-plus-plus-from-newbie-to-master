#include<iostream>

using namespace std;

int main()
{
	int password{ 98989891 };
	int crackPass{};
	//goto 版本
lcrack:
	if (crackPass != password)
	{
		crackPass++;
		goto lcrack;
	}
	cout << "路由PIN = " << crackPass << endl;

	// for 版本
	for (crackPass = 0; crackPass < 100000000; crackPass++)
	{
		if (crackPass != password)
		{
			crackPass++;
		}
		if (crackPass == password)
		{
			break;
		}
	}
	cout << "路由PIN = " << crackPass << endl;

	// while 版本
	crackPass = 0;
	while (crackPass < 100000000)
	{
		if (crackPass != password)
		{
			crackPass++;
		}
		if (crackPass == password)
		{
			break;
		}
	}
	cout << "路由PIN = " << crackPass << endl;

	// do ... while 版本
	crackPass = 0;
	do
	{
		if (crackPass != password)
		{
			crackPass++;
		}
		if (crackPass == password)
		{
			break;
		}
	} while (crackPass < 100000000);
	cout << "路由PIN = " << crackPass << endl;
	return 0;
}