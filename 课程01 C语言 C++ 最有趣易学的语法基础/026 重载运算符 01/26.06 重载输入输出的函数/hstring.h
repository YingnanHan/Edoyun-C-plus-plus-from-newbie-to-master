#pragma once

#ifndef _HTDSTRING_
#define _HTDSTRING_

#include<iostream>

using namespace std;

class hstring
{
	unsigned short usmlen;							// 字符串的内存长度
	char* cstr;										// 字符串的长度
	unsigned short uslen;							// 字符串的内容
	unsigned short GetLength(const char* str) const;
	void CopyStr(char* dest, const char* source);
public:
	char* c_str()
	{
		return cstr;
	}
	hstring();
	~hstring()
	{
		if (cstr != nullptr)
		{
			delete cstr;
		}
	}
	hstring(const char* str);
	hstring(const hstring& str);
	hstring& operator=(const hstring& str);
	hstring& operator=(const char* str);
	// 自定义实现类型转换复制重载运算符
	hstring& operator=(const int& value);			// 作业
	hstring& operator=(const float& value);			// 作业
	hstring& operator=(const long long& value);		// 作业
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str)
	{
		return *this << str;
	}
	// bool ResetMemory(unsigned short);			// 作业 重设缓冲区的大小
	// unsigned short GetMemory();					// 作业 获取当前缓冲区的大小
	// unsigend short GetLength();					// 作业 获取字符串长度
};
std::ostream& operator<<(std::ostream& _cout, hstring& _str); //输出运算符重载
std::istream& operator>>(std::istream& _cin, hstring& _str); //输出运算符重载
#endif