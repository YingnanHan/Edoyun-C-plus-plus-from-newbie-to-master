#include<iostream>

using namespace std;

int main()
{
	// x86ϵͳ��32bit
	// x64ϵͳ��64bit
	// ��ͬ���͵�ָ��ͱ�����ַ����������ֱ�Ӹ�ֵ
	int* ptr1{};
	std::cout << "intָ��Ĵ�СΪ:\t" << sizeof(ptr1) << std::endl;
	char* ptr2{};
	std::cout << "charָ��Ĵ�СΪ:\t" << sizeof(ptr2) << std::endl;

	///////////////////////////////////////////////////////////////

	unsigned ua{ 99901 };
	int       a{ 9999 };

	int* ptr(&a);
	ptr = (int*)&ua;	// ��ָ�����ͽ���ǿ��ת��
	long long* uptr{ (long long*)&ua };
	ptr = (int*)&ua;

	std::cout << sizeof(ptr) << std::endl;
	char* ctr{};

	*ptr = -1;

	ctr = (char*)ptr;

	*ctr = 'A';

	std::cout << sizeof(ctr) << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << *uptr << std::endl;

	return 0;
}