#include<iostream>

using namespace std;

namespace t
{
	int value;
}

using namespace t; // ��ȫ�ֵ���t�����ռ��еı�����������

int p{}; // ���û��д����ô��������ȫ�������ռ� �����ⲿ��������
const int q{}; // �����ڲ���������
int x = 2000;  // �����ⲿ��������
extern void test();

namespace t //�������ռ����չ������������չ��
{
	int height{1250};
}

int main()
{
	t::value = 255;
	cout << "Hello World!" << endl;
	int p{};
	::p = 100; // ���ʵ���ȫ�������ռ��е�p
	test();
	return 0;
}