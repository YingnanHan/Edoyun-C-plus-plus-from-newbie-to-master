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
	std::cout << len; // ����ַ����ĳ���
	//char strRt[0x20]; //��ջ�Ϸ���ֲ�����
	char* strRt = new char[0x20];
	memcpy(strRt, str, len);
	return strRt; //�����Է��ؾֲ�����
}

int main()
{
	// ��
	char* str;
	str = (char*)"���"; // str������ָ����һ����������ָ��
	std::cout << str << endl;;
	// ��
	str = cstr("123123");
	cout << str;
	return 0;
}