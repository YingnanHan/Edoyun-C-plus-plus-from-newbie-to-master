#include<iostream>
#include<array>

using namespace std;

int main()
{
	int studentIdA[5] = { 1001, 1002, 1003, 1004, 1005 };
	int studentIdB[5] = { 1001, 1002, 1003, 1004, 1005 };
	std::array<int, 5> arr1{ 1001,1002,1003,1004,1005 };
	std::array<int, 5> arr2{ 1001,1002,1003,1004,1005 };
	// arr1.fill(999); // ������Ԫ�����ó�999
	// ����Խ����ܳ��� 
	std::cout << studentIdA[100] << std::endl; // ���ᱨ��
	// std::cout << arr.at(100) << std::endl; // ���㶨λ����

	// ����֮��ıȽ� ���ڲ�δ�������������Լ�==����������ﲻ���Խ��бȽ�
	// std::cout << studentIdA == studentIdB << std::endl;
	// std::cout << arr1 == arr2 << std::endl;
	return 0;
}