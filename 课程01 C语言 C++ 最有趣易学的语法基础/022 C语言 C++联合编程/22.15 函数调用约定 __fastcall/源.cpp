#include<iostream>

using namespace std;

int __fastcall ave(int a, int b) // ʹ�üĴ��������ݲ���
{
	return (a + b) / 2;
}

int main()
{
	cout << ave(1, 2);
	// 00007FF7BD41187B  mov         edx, 2
	// 00007FF7BD411880  mov         ecx, 1
	return 0;
}

/*
��һ������ͨ��ecx����
�ڶ�������ͨ��edx����
ʣ�������ջ˳�� ���ҵ���
��ջƽ�⣺�����Լ��ָ�ջƽ��
fastcall�ĺ���ִ���ٶȱȽϿ�
*/