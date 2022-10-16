#include<iostream>
#include<string>

using namespace std;

int main()
{
	// Ctrl K C 加注释
	// Ctrl K U 取消注释

	// 01 要求输入一个0-15数字将其转换成十六进制
	//int cin;
	//std::cin >> cin;
	//string str{"0123456789abcdef"};
	//std::cout << str[cin];
	//std::cout << std::endl;

	// 02 判定字符串相等 C
	//char* str1{ (char*)"123456" }; // 这两个变量内存地址一样是由操作系统优化的 
	//char* str2{ (char*)"123456" }; // 但是实际上不是一样的
	//char* str3 = new char[7]{ "123456" }; //在堆空间新开辟一块内存
	//// 下面的实验表明 == 适用于判定内存地址是否相等
	//if (str1 == str2)
	//{
	//	std::cout << "str1 == str2:" << std::endl;
	//}
	//if (str1 == str3)
	//{
	//	std::cout << "str1 == str3:" << std::endl;
	//}
	//else
	//{
	//	std::cout << "str1 != str3:" << std::endl;
	//}

	// 03 字符串之间的比较 C++ 方法01
	/*string str_1{ "abcdef" };
	string str_2{ "bcdefg" };

	if (str_1 > str_2)
	{
		std::cout << "str_1>str_2";
	}
	else
	{
		std::cout << "str_1<str_2";
	}*/

	// 04 字符串之间的比较 C++ 方法02
	//string str_1{ "abcdef" };
	//string str_2{ "bcdefg" };
	//std::cout << str_1.compare(str_2); // 如果str_1 < str_2 会返回负数 否则 如果str_1 < str_2 返回正数 相等则返回0
	//std::cout << str_1.compare(0,5, str_2, 0, 5); //这里是使用str1[0:5] 与 str2[0:5]进行比较

	// 05 字符串的搜索功能
	string str_1{ "username:56203;student_id:560001" };
	string studentId;

	studentId = str_1.substr(str_1.find("student_id") + 11); //手动调节偏移位置
	std::cout << "student_id = " << studentId << std::endl;

	return 0;
}