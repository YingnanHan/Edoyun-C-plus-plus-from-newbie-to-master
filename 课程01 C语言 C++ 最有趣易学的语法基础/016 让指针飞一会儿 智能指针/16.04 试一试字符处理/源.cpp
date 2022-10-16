#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<locale>

using namespace std;

int main()
{
	// 01 char 类型字符串
	//char Name[0x10];
	//printf("请输入您的名字:");
	//scanf_s("%s", Name, 5); // Tony 占用四个字节 // 设置最多输入5个
	//printf("您的名字是:{%s}", Name);

	// 02 wchar 类型字符串
	//setlocale(LC_ALL, "chs"); // 设置支持Unicode中文字符
	////wchar_t wstr[0x5];
	//wchar_t* wstr = new wchar_t[0x5];
	//wscanf(L"%s", wstr); 
	//wprintf(L"您的名字是{%s}",wstr);

	//int x{ 0x10 };
	//char Name{ 0x10 };
	//std::cout << x << " " << Name << std::endl; // C++中对char类型的指针优先当做字符串处理

	//wchar_t wstr[ 0xFF ];
	//setlocale(LC_ALL, "chs");//设置本地字符集
	//std::wcout << L"请输入您的名字:" << std::endl;
	//std::wcin >> wstr;
	//std::wcout << "\n" << L"您的名字是:";
	//std::wcout << wstr;

	char str[0xff];
	std::cin >> str; //一个中文算两个字节
	cout << std::strlen(str) << std::endl;


	return 0;
}