#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<locale>

using namespace std;

int main()
{
	// 01 char �����ַ���
	//char Name[0x10];
	//printf("��������������:");
	//scanf_s("%s", Name, 5); // Tony ռ���ĸ��ֽ� // �����������5��
	//printf("����������:{%s}", Name);

	// 02 wchar �����ַ���
	//setlocale(LC_ALL, "chs"); // ����֧��Unicode�����ַ�
	////wchar_t wstr[0x5];
	//wchar_t* wstr = new wchar_t[0x5];
	//wscanf(L"%s", wstr); 
	//wprintf(L"����������{%s}",wstr);

	//int x{ 0x10 };
	//char Name{ 0x10 };
	//std::cout << x << " " << Name << std::endl; // C++�ж�char���͵�ָ�����ȵ����ַ�������

	//wchar_t wstr[ 0xFF ];
	//setlocale(LC_ALL, "chs");//���ñ����ַ���
	//std::wcout << L"��������������:" << std::endl;
	//std::wcin >> wstr;
	//std::wcout << "\n" << L"����������:";
	//std::wcout << wstr;

	char str[0xff];
	std::cin >> str; //һ�������������ֽ�
	cout << std::strlen(str) << std::endl;


	return 0;
}