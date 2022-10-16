#include<iostream>
#include<array>

using namespace std;

int main()
{
	int studentIdA[5] = { 1001, 1002, 1003, 1004, 1005 };
	int studentIdB[5] = { 1001, 1002, 1003, 1004, 1005 };
	std::array<int, 5> arr1{ 1001,1002,1003,1004,1005 };
	std::array<int, 5> arr2{ 1001,1002,1003,1004,1005 };
	// arr1.fill(999); // 将所有元素设置成999
	// 数组越界可能出错 
	std::cout << studentIdA[100] << std::endl; // 不会报错
	// std::cout << arr.at(100) << std::endl; // 方便定位错误

	// 数组之间的比较 由于并未冲在输出运算符以及==运算符，这里不可以进行比较
	// std::cout << studentIdA == studentIdB << std::endl;
	// std::cout << arr1 == arr2 << std::endl;
	return 0;
}