#include<iostream>

using namespace std;

int add(int& a, int& b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 0;
	int b = 9;
	cout << add(1, 1); 
	// cout << add(a, b) << endl; //����(�)	E0308	�ж�� ���غ��� "add" ʵ��������б�ƥ��:	21.03 ������ֵ����ͬʱ���ػ��������	C : \Users\20613\Desktop\�׵��� C++ ȫջ ����\�γ�01 C���� C++ ����Ȥ��ѧ���﷨����\021 ���������뺯��ģ��\21.03 ������ֵ����ͬʱ���ػ��������\Դ.cpp	20

}
