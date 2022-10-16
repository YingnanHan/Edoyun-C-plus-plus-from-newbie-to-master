#include<iostream>
#include<locale>

using namespace std;

int main()
{
	char str[0xFF]{ "Hello" }; // char 类型字符每一个为一个字节
	const char* strA = "Hello 张三"; // char类型下GBK编码对应的中文是两个字节
	const char* strB = new char[0xff] { "Hello" };

	std::cout << strA; //一般的字符串输出
	cout << endl;

	wchar_t wstr[0xFF]{ L"Hello 张三" }; // L表示的是宽字节的常量 每一个字符占用两个字节
	const wchar_t* wstr1 = L"Hello 张三";
	// std::cout << wstr1; //一般的字符串输出对wchar不起作用
	setlocale(LC_ALL, "chs");// 设定控制台正常打印宽字符中文(按照Unicode编码表翻译映射) 如果不进行设置则不会打印对应的中文
	std::wcout << wstr1; // 使用wcout专门输出wchar类型字符串
	// std::cout << wstr1; //这么些会直接导致输出宽字节字符串在底层存储的十六进制数
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		cout << short(wstr[i]) << endl;
	}
}