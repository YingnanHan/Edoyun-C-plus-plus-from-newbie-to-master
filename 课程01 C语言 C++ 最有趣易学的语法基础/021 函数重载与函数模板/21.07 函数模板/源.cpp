#include<iostream>

template<typename T>
T ave(T a, T b, T c)
{
	return (a + b + c) / 3;
}

int main()
{
	int a{ 100 }, b{ 200 }, c{ 300 };
	// c = *ave(&a, &b, &c); // ָ���ں���ģ���еĴ����÷�
	// �˹��趨ʵ�ʵĲ������� ����������趨 ��ô�ͻ��б����������ƶ�
	std::cout << ave<float>(12.0f, 23.9f, 2.0f) << std::endl;
	std::cout << ave<int>(12, 23, 2) << std::endl;
	std::cout << (char)ave<char>((char)11, char(12), char(13)) << std::endl;
	return 0;
}