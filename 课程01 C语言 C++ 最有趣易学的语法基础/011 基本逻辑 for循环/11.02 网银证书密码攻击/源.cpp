#include<iostream>

using namespace std;

int main()
{
	int password, repassword;
input:
	std::cout << "��������һ����λ��������:";
	std::cin >> password;
	std::cout << "�����ٴ���������:";
	std::cin >> repassword;
	if (password == repassword)
	{
		system("cls");
		std::cout << "�ƽ��������!";
		for (int hackPass = 0; hackPass < 1000000; hackPass++)
		{
			if (hackPass == password)
			{
				std::cout << "�����õ�������:" << hackPass << std::endl;
				goto lexit;
			}
		}
	}
	else
	{

	}
lexit:
	std::cout << "\n�����ƽ�ɹ�:";
	return 0;
}