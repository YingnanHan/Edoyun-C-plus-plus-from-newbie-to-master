#include<iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int* d = new int[5];

	// �Եı�����ʵ���ǿ����ڴ棬C++�аѶѳ�Ϊ���ɴ洢��
	// ֻҪ����ĳ�����غ�û�б�ռ�õĿ����ڴ涼������
	// �洢��,ʹ��new����malloc����һ���µ��ڴ���������
	// ����ϵͳ�ڶ��ϲ���
	// ջ�ǳ����ڱ���ʱ���Ѿ�ȷ���˴�С��һ���ڴ�������
	// Ҫ��������ʱ�����Ĵ洢��ջ��Ч��Ҫ���ڶѣ���������
	// ����

	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &c << std::endl;
	std::cout << &d << std::endl;
	std::cout << d << std::endl;


	return 0;
}