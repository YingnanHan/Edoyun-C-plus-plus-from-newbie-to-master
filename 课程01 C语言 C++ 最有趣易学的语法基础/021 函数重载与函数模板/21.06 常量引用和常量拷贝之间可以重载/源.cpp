#include<iostream>

using namespace std;

// �������������ֳ����ͷǳ��������ǲ������������ú�ֵ����

int ave(const int& a, const int& b)
{
	cout << "int ave(const int& a, const int& b) called:" << ends;
	return 0.5 * (a + b);
}

int ave(int& a, int& b)
{
	cout << "int ave(int& a, int& b) called:" << ends;
	return 0.5 * (a + b);
}

int main()
{
	const int a = 10;
	const int b = 20;

	int& aa = const_cast<int&>(a);
	int& bb = const_cast<int&>(b);

	ave(a, b);
	ave(aa, bb);

	return 0;
}