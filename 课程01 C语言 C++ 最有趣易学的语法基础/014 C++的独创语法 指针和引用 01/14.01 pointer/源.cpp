#include<iostream>

using namespace std;

int main()
{
	// int* a1, b1; // b1��ָ��
	// int *a2, b2; // b2�Ǳ���

	int a{ 5000 };
	int* pa{ &a }; // ��������Ҫ��Ӧ

	// pa = 0x5000;
	//PA = A���ڴ��ַ
	//*PA ��дA���ڴ�ռ�

	std::cout << "�ڴ��ַ��" << pa << "\na = " << a;
	std::cout << std::endl;
	*pa = 6666; //ֱ�Ӳ����ڴ�ռ䣬�޸�ָ��Ŀ���ֵ
	std::cout << "�ڴ��ַ��" << pa << "\na = " << a;
	(*pa)++;
	std::cout << std::endl;
	std::cout << "�ڴ��ַ��" << pa << "\na = " << a;

	return 0;
}