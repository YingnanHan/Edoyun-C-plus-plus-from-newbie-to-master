#include<iostream>

using namespace std;

// �ӱ������ĽǶȺ�������һ��extern�ã����Բ��ø������η�
extern int ave(int a, int b); // ���� �����������Ӱ�캯����ʹ�� ���Ƕ���ֻ������һ��

int all; // ����
extern int all_; // ����һ������ ר�����ȫ�ֱ���

// ȫ�ֱ�����һ���̶��ĵ�ַ���������������ȫ�ֱ�����

int main()
{
	int c = ave(1, 2);
	std::cout << c << std::endl;
	std::cout << "all_ = " << all_ << std::endl;
	return 0;
}

int pve()
{
	return ave(1, 2); // ʹ����ǰ������ʹ�������������Ի������
}

int ave(int a, int b) // ����
{
	// pve(); // ������Ļ�����ÿ��ܻᵼ��ջ���
	return (a + b) / 2;
}

int all_ = 400; //����