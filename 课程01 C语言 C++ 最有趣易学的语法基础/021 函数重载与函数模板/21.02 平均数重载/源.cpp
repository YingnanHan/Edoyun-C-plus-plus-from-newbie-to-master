#include<iostream>

using namespace std;

int ave(int a, int b)
{
	cout << "ave ���� int ����";
	return (a + b) / 2;
}

int ave(int a, int b, int c)
{
	cout << "ave ���� int ����";
	return (a + b + c) / 3;
}

float ave(float a, float b)
{
	cout << "ave ���� float ����";
	return (a + b) / 2.0;
}

int main()
{
	cout << ave(100, 100) << endl;
	cout << ave(100, 100) << endl;
	cout << ave(100.0f, 100.0f) << endl;
	return 0;
}