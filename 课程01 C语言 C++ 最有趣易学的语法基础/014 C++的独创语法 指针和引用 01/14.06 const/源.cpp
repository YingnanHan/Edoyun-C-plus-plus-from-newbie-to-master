#include<iostream>

using namespace std;

int main()
{
	/*
	//01
	const int a{ 100 };
	const int b{ 200 };
	int c{ 300 };

	const int* ptr = &a; //ָ�볣��

	ptr = &c; // �������޸�ָ��ָ�����ĵ�ֵ�����ǿ����޸�ָ��ָ���λ��
	// *ptr = 400; //����

	*/


	/*
	//02
	const int a{ 100 };
	const int b{ 200 };
	int c{ 300 };

	int* const ptr = &a; //����ָ��

	ptr = &b; // �����޸�ָ��ָ�����ĵ�ֵ�����ǲ������޸�ָ��ָ���ֵ
	*ptr = 400; //������
	*/

	/*
	// 03
	const int a{ 100 };
	const int b{ 200 };
	int c{ 300 };

	const int* const ptr = &a;

	//ptr = &b; // �������޸�ָ��ָ�����ĵ�ֵ���������޸�ָ��ָ���ֵ
	//*ptr = 400; //������
	*/


	// 04
	const int a{ 1000 };
	const int b{ 1400 };
	const int* const ptr{ &a };

	int* ptrA{ (int*)&a };
	*ptrA = 9500;
	std::cout << *ptrA << std::endl;
	std::cout << a;

	return 0;
}