#include<iostream>

using namespace std;

int main()
{
	unsigned x;
	std::cin >> x;
	// ����40
	int* p = (int*)malloc(sizeof(int) * x); // �����ڴ� ����ʹ���û��Զ���ķ�ʽ�������·����ڴ�ĺ���

	if (p == nullptr)
	{
		std::cout << "�ڴ����ʧ��!";
	}
	else
	{
		p[0] = 952;
		p[1] = 953;
		p[2] = p[0] * p[1];

		std::cout << "p[0] = " << p[0] << std::endl;
		std::cout << "p[1] = " << p[1] << std::endl;
		std::cout << "p[2] = " << p[2] << std::endl;
	}
	return 0;
}

