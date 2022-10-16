#pragma once
#ifndef _HTDSTRING_
#define _HTDSTRING_
#include<iostream>

#define hstring_no_char -1

class hstring
{

	unsigned short usmlen;							// 字符串的内存长度
	unsigned short uslen;							// 字符串的长度
	char* cstr;										// 字符串的内容
	unsigned short GetLength(const char* str) const;
	void CopyStrs(char* dest, const char* source);
public:
	inline static char nochar = -1;
	char* c_str() { return cstr; }
	~hstring();

	// hstring();
	hstring(char clen = 0x32);
	hstring(const char* str);						// 利用C字符串来构造hstring
	hstring(const hstring& str);					// 利用hstring来构造hstring
	hstring& operator=(const hstring& str);
	// hstring& operator=(const long long& value);  // 实现long long 类型 作业1
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str);
	// bool ResetMemory(unsigned short);			// 作业 重设缓冲区的大小
	// unsigned short GetMemory();					// 作业 获取当前缓冲区的大小
	// unsigend short GetLength();					// 作业 获取字符串长度

	const char& operator[](const unsigned short index)const;

	const char& operator()();

	//截取字符串
	hstring operator()(const unsigned short start, const unsigned short length) const;

	hstring& operator+(int val)
	{
		char str[0x20]{};
		int len{ 0x1F };
		bool bzs = val >= 0;
		val = val * (bzs * 2 - 1);

		do
		{
			str[--len] = val % 10 + 48;
		} while (val = val / 10);

		str[len = len - 1 * (1 - bzs)] = '-' * (bzs + 1) * (1 - bzs) + str[len] * bzs;
		// 拼接
		unsigned short slen = uslen + 0x20 - len - 1;
		if (slen > usmlen)
		{
			char* lstr = cstr;
			cstr = new char[slen] {}; // 重新分配内存
			usmlen = slen;//修正内存的长度
			memcpy(cstr, lstr, uslen);
			delete[] lstr; // 删除内存
		}

		memcpy(cstr + uslen - 1, str + len, 0x20 - len);
		uslen = slen; //字符串长度修正
		return *this;
	}

	hstring& operator+(unsigned val)
	{
		char str[0x20]{};
		int len{ 0x1F };
		bool bzs = val >= 0;
		val = val * (bzs * 2 - 1);

		do
		{
			str[--len] = val % 10 + 48;
		} while (val = val / 10);

		str[len = len - 1 * (1 - bzs)] = '-' * (bzs + 1) * (1 - bzs) + str[len] * bzs;
		// 拼接
		unsigned short slen = uslen + 0x20 - len - 1;
		if (slen > usmlen)
		{
			char* lstr = cstr;
			cstr = new char[slen] {}; // 重新分配内存
			usmlen = slen;//修正内存的长度
			memcpy(cstr, lstr, uslen);
			delete[] lstr; // 删除内存
		}

		memcpy(cstr + uslen - 1, str + len, 0x20 - len);
		uslen = slen; //字符串长度修正
		return *this;
	}

	operator int()
	{
		short val{ 0 };
		int i = cstr[0] == '-'; //标尺
		while (cstr[i] >= '0' && cstr[i] <= '9')
		{
			val = val * 10 + cstr[i++] - 48;
		}
		val = val * ((cstr[0] != '-') * 2 - 1); // 如果是负数则变成附属

		return val;
	}
};
std::ostream& operator<<(std::ostream& _cout, hstring& _str); //输出运算符重载
std::ostream& operator<<(std::ostream& _cout, hstring&& _str); //输出运算符重载,延长生命周期
std::istream& operator>>(std::istream& _cin, hstring& _str);  //输出运算符重载
#endif