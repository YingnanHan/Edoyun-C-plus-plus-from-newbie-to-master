#include<iostream>
#include<conio.h>

using namespace std;

#pragma warning(disable : 4996)

int main()
{
	//// ��ͳC���뷽ʽ
	//printf("I'm very handsome!\n"); // �����÷�
	//printf("I'm %s\,and I'm %d years old.\n","Mike",19); // ������ʽ���÷�
	//printf("I'm of %f cm's height\n", 190); // ��ʽ���÷�
	//printf("My lucky number is 0x%x\n", 999); //ʮ�����Ƹ�ʽ��
	//printf("My lucky number is %+05d\n", 999); //ʮ����λ���=5��ʽ��

	//int age{ 0 };
	//int a;
	//int b;
	//int c;
	//int d;
	//scanf("%d%d%d%d", &a, &b, &c, &d);//C��ʽ����
	//printf("%d%d%d%d", &a, &b, &c, &d);//C��ʽ���

	// �ִ���ʽ
	int uin = _getch(); // �ӿ���̨��������һ���ַ� ����ASCII��ֵ
	std::cout << uin << std::endl;


	return 0;
}