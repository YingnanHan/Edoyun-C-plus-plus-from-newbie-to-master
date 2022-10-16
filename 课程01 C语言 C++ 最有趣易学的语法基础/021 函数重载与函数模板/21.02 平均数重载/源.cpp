#include<iostream>

using namespace std;

int ave(int a, int b)
{
	cout << "ave 两个 int 参数";
	return (a + b) / 2;
}

int ave(int a, int b, int c)
{
	cout << "ave 三个 int 参数";
	return (a + b + c) / 3;
}

float ave(float a, float b)
{
	cout << "ave 两个 float 参数";
	return (a + b) / 2.0;
}

int main()
{
	cout << ave(100, 100) << endl;
	cout << ave(100, 100) << endl;
	cout << ave(100.0f, 100.0f) << endl;
	return 0;
}