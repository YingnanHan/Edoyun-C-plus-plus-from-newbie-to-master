#include<iostream>

using namespace std;

template<typename T, short count>
T ave(T(&ary)[count])
{
	T sum = 0;
	for (auto x : ary)
	{
		sum += x;
	}
	return sum / count;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	cout << ave(a); //�Զ����ƶϳ�����Ĵ�С��Ҳ����˵count��ֵ�����a��ʵ�ʴ�С�ƶϳ���
}