#include<iostream>

using namespace std;

// �ֲ���̬������ȫ�ֱ���������������һ����
int ave(int a, int b)
{
	static int count{ 200 }; // ����count֮����ʼ��һ�Σ�������Ϊ���������µ��ö����³�ʼ��
	std::cout << count++ << std::endl;
	return (a + b) / 2;
}

int main()
{
	ave(1, 2);
	ave(1, 2);
	ave(1, 2);
	ave(1, 2);
	ave(1, 2);
	ave(1, 2);
	return 0;
}