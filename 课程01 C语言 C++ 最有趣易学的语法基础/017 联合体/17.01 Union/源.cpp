#include<iostream>

using namespace std;

union USER
{
	short	sHP;
	int		nHp;
	double	fHp;
};

int main()
{
	USER user; // [][][][][][][][] ֱ�ӷ���˸��ֽ� ���ǲ�û�г�ʼ��
	std::cout << sizeof user << std::endl;

	// ���ȳ�ʼ��
	user.nHp = 0;
	user.sHP = -1; // [0xff][0xff][][][][][][]
	std::cout << &user.sHP << std::endl;
	// �ڴ��ַ����ͬ�� �����������ǹ����ڴ�ռ��
	// [100][0][?][?][?][?][?][?]
	std::cout << &user.nHp << std::endl;
}