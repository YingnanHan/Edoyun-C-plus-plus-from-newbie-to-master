#include<iostream>

using namespace std;

int main()
{

	int a[]{ 1001, 1002, 1003, 1004 };
	int* ptr{ &a[0] };

	std::cout << ptr << std::endl;

	ptr = ptr - 1; // ��ȥһ��������ռ�ֽڴ�С

	std::cout << a[0] << std::endl;

	std::cout << ptr << std::endl;
	std::cout << &a[1] << std::endl;
	// ָ��+1��ʱ�� ��ֵ�仯���� +1*ָ���Ӧ�������͵Ĵ�С
	std::cout << *ptr << std::endl;

	return 0;
}