#include<iostream>

using namespace std;

int main()
{
	int a{ 500 };
	int b{ 1000 };
	bool c = (a == b); // false true

	std::cout << boolalpha;// ����Ӣ����ĸ�ķ�ʽ�����������
	std::cout << c << std::endl;

	bool aa = {}; // Ĭ��ʹ��true����ʼ��,������ǿ���ô����false
	std::cout << aa << std::endl;

	// ��������ת��
	bool bA{ bool(100) };
	int nA{ bA }; // ���ʱ��bA=1
	std::cout << nA << std::endl;

	return 0;
}