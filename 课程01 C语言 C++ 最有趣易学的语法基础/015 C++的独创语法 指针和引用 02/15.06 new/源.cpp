#include<iostream>

using namespace std;

int main()
{
	int x;
	std::cout << "��������Ҫ������ڴ�Ĵ�С:";
	std::cin >> x;

	int* p{};
	p = new int{ x };

	delete[] p; //�ͷŷ���Ŀռ�

	return 0;
}