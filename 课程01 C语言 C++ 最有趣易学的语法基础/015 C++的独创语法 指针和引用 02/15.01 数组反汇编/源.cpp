#include<iostream>

using namespace std;

int main()
{
	int a[5];

	// int* ptrA{ &a[0] };
	int* ptrA{ a }; //�ȼ�д��

	*ptrA = 5;
	*ptrA++;

	a[0] = 5;
	a[0] = 5;
	a[0] = 5;

	std::cout << a << std::endl;
	std::cout << &a[0] << std::endl;
	std::cout << ptrA[1] << std::endl;
	std::cout << a[1] << std::endl;
	// �ײ���˵�������һ���ڴ��ַ�����������µ���������������Ӧ���׵�ַ�ᱻ��������װ��Ϊһ������
	std::cout << sizeof a << std::endl;
	std::cout << sizeof ptrA << std::endl;


	int test[2][5] =
	{
		{1001,1002,1003,1004,1005},
		{2001,2002,2003,2004,2005}
	};

	int testA[2][6] =
	{
		{0,1001,1002,1003,1004,1005},
		{0,2001,2002,2003,2004,2005}
	};

	std::cout << "testA[0] = " << testA[2] << std::endl;

	//int* ptest{ (int*)test }; // ָ������ 5��int���͵�ָ��
	int* ptestA[5]; //����ָ�� 5��һ��
	int(*ptest)[6] { testA }; // ��ά����ָ��

	std::cout << test[1][4] << std::endl;
	std::cout << ptest[0][1] << std::endl;

	std::cout << sizeof ptest << std::endl;

	return 0;
}