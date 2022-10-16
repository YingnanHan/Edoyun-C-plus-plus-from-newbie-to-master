#include<iostream>

using namespace std;

int main()
{
	int password, repassword;
input:
	std::cout << "请您设置一个六位数字密码:";
	std::cin >> password;
	std::cout << "请您再次输入密码:";
	std::cin >> repassword;
	if (password == repassword)
	{
		system("cls");
		std::cout << "破解程序启动!";
		for (int hackPass = 0; hackPass < 1000000; hackPass++)
		{
			if (hackPass == password)
			{
				std::cout << "您设置的密码是:" << hackPass << std::endl;
				goto lexit;
			}
		}
	}
	else
	{

	}
lexit:
	std::cout << "\n密码破解成功:";
	return 0;
}