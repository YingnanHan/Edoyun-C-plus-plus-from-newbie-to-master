#include<iostream>

static int a = 350;
extern const int pt = 1000; // ���ڲ���������ʹ��externת��Ϊ�ⲿ��������
extern int x;

static void Test() // ʹ��static�ᵼ��Test�����ڲ���������
{
	std::cout << "Test";
}