#include<iostream>

using namespace std;

//// �ֲ���̬������ȫ�ֱ���������������һ����
//int ave(int a, int b)
//{
//	static int count{ 200 }; // ����count֮����ʼ��һ�Σ�������Ϊ���������µ��ö����³�ʼ��
//	std::cout << count++ << std::endl;
//	return (a + b) / 2;
//}

inline int add(int a, int b) // �������Զ��Ż�����
{
	return a + b;
}

int main()
{
	// 01
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);
	//ave(1, 2);

	// 02
	std::cout << add(1, 1); // ������ֻ�ж��ٴ���ĺ���ʹ��inline����Ч��

	return 0;
}