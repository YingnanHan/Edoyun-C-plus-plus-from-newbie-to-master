#include<iostream>

using namespace std;

int main()
{
	int password{ 98989891 };
	int crackPass{};
	//goto �汾
lcrack:
	if (crackPass != password)
	{
		crackPass++;
		goto lcrack;
	}
	cout << "·��PIN = " << crackPass << endl;

	// for �汾
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
	cout << "·��PIN = " << crackPass << endl;

	// while �汾
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
	cout << "·��PIN = " << crackPass << endl;

	// do ... while �汾
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
	cout << "·��PIN = " << crackPass << endl;
	return 0;
}