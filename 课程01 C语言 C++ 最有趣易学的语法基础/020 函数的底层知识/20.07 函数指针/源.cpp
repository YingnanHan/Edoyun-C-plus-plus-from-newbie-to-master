#include<iostream>

using namespace std;

typedef char(*pfAdd)(int, int); // ����һ������ָ������
using pfAdd = char(*)(int, int); // ����һ������ָ������
using pRole = int(*)(int hp, int mp); // ����һ������ָ������

int AddX(int a, int b)
{
	return a * 10 + b;
}

float Add(int a, int b)
{
	return (a + b)/2;
}

struct Role
{
	int hp;
	int mp;
};

int Exp(Role r1)
{
	return r1.hp + r1.mp;
}

int main()
{
	// 01
	int(*pAdd)(int, int) {(int(*)(int, int))Add}; // ����һ������ָ�� (int(*)(int, int))��Addת��Ϊָ������
	cout << pAdd(1, 1) << std::endl; //����õ��ķ���ֵ����int�����ֵ� ����һ������ָ��
	cout << sizeof pAdd << std::endl;
	
	// 02
	char(*pAdd_)(int, int) { (char(*)(int, int))Add };
	cout << pAdd_(1, 1) << std::endl; //����õ��ķ���ֵ����char�����ֵ�

	// 03
	using pFadd = char(*)(int, int); // ��������ָ������
	pFadd pFadd1 = (pFadd)pAdd;
	pFadd1(1, 1);
	
	// 04 ��ֳ���
	struct Role r { 100, 100 };
	cout << Exp(r) << endl;

	// 05 
	Role r1{ 100, 350 };
	pRole pExp = (pRole)Exp;
	cout << pExp(100, 350); //ע������Բ����Ľ��ͣ�ʵ���Ͼ��Ƕ��ڴ��ַ�����
	return 0;
}