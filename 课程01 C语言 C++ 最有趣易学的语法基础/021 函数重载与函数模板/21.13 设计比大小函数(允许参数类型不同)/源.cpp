#include<iostream>

template<typename T1, typename T2>
// auto bigger(T1 &a, T2 &b) -> decltype(a > b ? a : b)
decltype(auto) bigger(T1 &a, T2& b)
{// �����Ҫǿ��ָ������������ô����Ҫ����decltype
	return a > b ? a : b;
}

int main()
{
	char a = 10;
	int b = 500;
	std::cout << bigger(a, b); //ԭ����decltype���ص����������ͣ����������ﴫ��Ĳ������������Ͳ�һ��Ϊ�˱��澫�Ȳ���ʧ�������û��ʹ������
}