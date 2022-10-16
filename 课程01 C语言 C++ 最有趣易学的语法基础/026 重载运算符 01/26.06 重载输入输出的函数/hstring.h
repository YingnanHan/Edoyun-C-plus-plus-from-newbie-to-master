#pragma once

#ifndef _HTDSTRING_
#define _HTDSTRING_

#include<iostream>

using namespace std;

class hstring
{
	unsigned short usmlen;							// �ַ������ڴ泤��
	char* cstr;										// �ַ����ĳ���
	unsigned short uslen;							// �ַ���������
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
	// �Զ���ʵ������ת���������������
	hstring& operator=(const int& value);			// ��ҵ
	hstring& operator=(const float& value);			// ��ҵ
	hstring& operator=(const long long& value);		// ��ҵ
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str)
	{
		return *this << str;
	}
	// bool ResetMemory(unsigned short);			// ��ҵ ���軺�����Ĵ�С
	// unsigned short GetMemory();					// ��ҵ ��ȡ��ǰ�������Ĵ�С
	// unsigend short GetLength();					// ��ҵ ��ȡ�ַ�������
};
std::ostream& operator<<(std::ostream& _cout, hstring& _str); //������������
std::istream& operator>>(std::istream& _cin, hstring& _str); //������������
#endif