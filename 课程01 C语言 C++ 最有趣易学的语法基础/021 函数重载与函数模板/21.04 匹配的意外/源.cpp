#include<iostream>

using namespace std;

int ave(int* pa, int count)
{
	return 0;
}

// �������������ĺ�����һ���ģ����ܱ�����Ϊ��������
//int ave(int pa[], int count)
//{
//	return 0;
//}

int ave(int &a, int &b)
{
	std::cout << "ave ���� int ���ò���";
	return (a + b) / 2;
}

float ave(float a, float b)
{
	std::cout << "ave ���� float ����";
	return (a + b) / 2;
}

int ave(int a, int b, int c)
{
	std::cout << "ave ���� int ����";
	return (a + b + c) / 3;
}

float ave(float a, float b, float c)
{
	std::cout << "ave ���� float ����";
	return (a + b + c) / 3;
}

//int ave(int& a, int& b) // �����ͨ������ʵ������ƥ���ʱ��ᵼ������
//{
//	std::cout << "ave ���� int ����";
//	return (a + b) / 2;
//}

int main()
{
	int &&a = 100;
	int &&b = 200;

	char aa = 100;
	char bb = 100;

	std::cout << ave(200.0f, 300.0f) << std::endl;
	std::cout << ave(2, 3) << std::endl;
	std::cout << ave(2, 3.4) << std::endl;
	std::cout << ave(2.0f, 3.0f) << std::endl;
	std::cout << ave(aa, bb) << std::endl; // ƥ�䵽��int���͵�����
	std::cout << ave(int(aa), int(bb)) << std::endl; //����ת�������õ�������ʱ�ı������Բ���������ð汾

	return 0;
}