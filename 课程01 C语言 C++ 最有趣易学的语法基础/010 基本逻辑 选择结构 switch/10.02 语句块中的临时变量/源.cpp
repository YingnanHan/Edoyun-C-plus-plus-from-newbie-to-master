#include<iostream>

using namespace std;

int main()
{
	if (int a, b, c; true) // C++17���﷨
	{
		a = 1;
		b = 2;
		c = 3;
	}
	else
	{
		a = 3;
		b = 2;
		c = 1;
	}

	switch (2)
	{
	case 2:
	{
		int a = 5;
	}
	case 3:
		// ���ﲻ����ʹ��a
		break;
	}

	switch (int a = 0; 2) // int a=0; ɾ����ᱨ��
	{
	case 2:
	{
		a = 5;
	}
	case 3:
		// ����ʹ��a C++17���﷨
		cout << a;
		break;
	}
	return 0;
}