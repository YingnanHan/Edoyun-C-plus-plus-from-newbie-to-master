#include<iostream>
#include<string>

using namespace std;

int main()
{
	// Ctrl K C ��ע��
	// Ctrl K U ȡ��ע��

	// 01 Ҫ������һ��0-15���ֽ���ת����ʮ������
	//int cin;
	//std::cin >> cin;
	//string str{"0123456789abcdef"};
	//std::cout << str[cin];
	//std::cout << std::endl;

	// 02 �ж��ַ������ C
	//char* str1{ (char*)"123456" }; // �����������ڴ��ַһ�����ɲ���ϵͳ�Ż��� 
	//char* str2{ (char*)"123456" }; // ����ʵ���ϲ���һ����
	//char* str3 = new char[7]{ "123456" }; //�ڶѿռ��¿���һ���ڴ�
	//// �����ʵ����� == �������ж��ڴ��ַ�Ƿ����
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

	// 03 �ַ���֮��ıȽ� C++ ����01
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

	// 04 �ַ���֮��ıȽ� C++ ����02
	//string str_1{ "abcdef" };
	//string str_2{ "bcdefg" };
	//std::cout << str_1.compare(str_2); // ���str_1 < str_2 �᷵�ظ��� ���� ���str_1 < str_2 �������� ����򷵻�0
	//std::cout << str_1.compare(0,5, str_2, 0, 5); //������ʹ��str1[0:5] �� str2[0:5]���бȽ�

	// 05 �ַ�������������
	string str_1{ "username:56203;student_id:560001" };
	string studentId;

	studentId = str_1.substr(str_1.find("student_id") + 11); //�ֶ�����ƫ��λ��
	std::cout << "student_id = " << studentId << std::endl;

	return 0;
}