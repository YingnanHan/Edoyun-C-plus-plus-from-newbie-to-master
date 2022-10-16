#include<iostream>

using namespace std;

int clen(const char* str)
{
	int i;
	for (i = 0; str[i]; i++);
	return ++i;
}

char* cstr(const char* str)
{
	int len = clen(str);
	std::cout << len; // 求得字符串的长度
	//char strRt[0x20]; //在栈上分配局部变量
	char* strRt = new char[0x20];
	memcpy(strRt, str, len);
	return strRt; //不可以返回局部变量
}

int main()
{
	// ①
	char* str;
	str = (char*)"你好"; // str仅仅是指向了一个字面量的指针
	std::cout << str << endl;;
	// ②
	str = cstr("123123");
	cout << str;
	return 0;
}