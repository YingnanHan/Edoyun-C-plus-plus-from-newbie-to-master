#include<iostream>

using namespace std;

int main()
{

	//while版本
	/*
	int password{0}, repassword{ 1 }, crackPass{};

	while (password != repassword)
	{
		system("cls");
		std::cout << "请输入一个六位数的密码:";
		std::cin >> password;
		std::cout << "请再输入一次:";
		std::cin >> repassword;
	}
	std::cout << "开始执行破解程序";
	while (crackPass != password)
	{
		crackPass++;
	}
	cout << "程序破解成功:密码为" << crackPass;
	*/

	//do while 版本
	int password{ 0 }, repassword{ 1 }, crackPass{ -1 };

	do
	{
		system("cls");
		std::cout << "请输入一个六位数的密码:";
		std::cin >> password;
		std::cout << "请再输入一次:";
		std::cin >> repassword;
	} while (password != repassword);
	std::cout << "开始执行破解程序";
	do
	{
		crackPass++;
	} while (crackPass != password);
	cout << "程序破解成功:密码为" << crackPass;

	return 0;
}