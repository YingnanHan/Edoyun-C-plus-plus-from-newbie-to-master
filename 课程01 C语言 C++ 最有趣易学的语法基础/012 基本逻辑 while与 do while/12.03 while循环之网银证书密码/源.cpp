#include<iostream>

using namespace std;

int main()
{

	//while�汾
	/*
	int password{0}, repassword{ 1 }, crackPass{};

	while (password != repassword)
	{
		system("cls");
		std::cout << "������һ����λ��������:";
		std::cin >> password;
		std::cout << "��������һ��:";
		std::cin >> repassword;
	}
	std::cout << "��ʼִ���ƽ����";
	while (crackPass != password)
	{
		crackPass++;
	}
	cout << "�����ƽ�ɹ�:����Ϊ" << crackPass;
	*/

	//do while �汾
	int password{ 0 }, repassword{ 1 }, crackPass{ -1 };

	do
	{
		system("cls");
		std::cout << "������һ����λ��������:";
		std::cin >> password;
		std::cout << "��������һ��:";
		std::cin >> repassword;
	} while (password != repassword);
	std::cout << "��ʼִ���ƽ����";
	do
	{
		crackPass++;
	} while (crackPass != password);
	cout << "�����ƽ�ɹ�:����Ϊ" << crackPass;

	return 0;
}