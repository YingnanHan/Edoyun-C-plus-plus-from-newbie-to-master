#include<iostream>

using namespace std;

double __stdcall ave(double a, double b)
{
	return (a + b) / 2;
}

int main()
{
	//__stacall������ջ˳�� ������
	// ��ջƽ��:�����Լ��ָ�ջƽ��
	// Windows �����WINAPI CALLBACK ����__stdcall�ĺ�
	// ���ɵĺ������ֻ���»��ߣ������@�Ͳ����ߴ�
	cout << ave(1, 2);
	return 0;
}