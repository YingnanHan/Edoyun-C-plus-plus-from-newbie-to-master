#include<iostream>

using namespace std;


template<typename T1, typename T2>
T1 ave(T2 a, T1 b)
{
	return (a + b) / 2;
}

template<typename T1, typename T2, typename T3>
T3 ave(T1 a, T2 b, int c=10) // ���Լ��������Ĺ̶�������������ȷ��������
{
	return (a + b) / 2;
}

int main()
{
	//cout << ave(100, 200);
	//cout<<ave<double, double>(100, 200.0); // ǿ��ָ��ģ�庯����������

	std::cout << ave<int, float, double>(100, 1); //��������ֻ�������ɹ������ƶϵĲ��������������ָ���������ͣ����������޷��ƶ�ģ�庯��

	return 0;
}
