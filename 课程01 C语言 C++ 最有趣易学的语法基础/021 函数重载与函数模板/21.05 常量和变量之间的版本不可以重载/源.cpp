#include<iostream>

using namespace std;

int ave(int a, int b)
{
	return 0.5 * (a + b);
}

//int ave(const int a, const int b) // ��ͬ���� ��Ϊ�������Ĳ������ǿ���,����Ҳ���Ա�������ʼ��
//{
//	return 0.5 * (a + b);
//}

int main()
{
	ave(100, 100);
	return 0;
}