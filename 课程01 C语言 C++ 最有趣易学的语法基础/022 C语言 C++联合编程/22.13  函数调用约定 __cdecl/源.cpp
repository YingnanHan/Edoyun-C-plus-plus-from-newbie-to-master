#include<iostream>

using namespace std;

double __cdecl ave(double a, double b)
{
	return (a + b) / 2;
}

int main()
{
	// __cdecl ������ջ˳�� ������ ��ջƽ�� ˭����˭ƽ�� ��˼�����ɵ��ú�����ƽ��
	// �����ĳ���ջ������֧�ֲ���������
	cout << ave(1, 2);
	return 0;
}