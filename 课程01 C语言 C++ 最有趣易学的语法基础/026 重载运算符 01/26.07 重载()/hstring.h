#pragma once
#ifndef _HTDSTRING_
#define _HTDSTRING_
#include<iostream>

#define hstring_no_char -1

class hstring
{

	unsigned short usmlen;							// �ַ������ڴ泤��
	unsigned short uslen;							// �ַ����ĳ���
	char* cstr;										// �ַ���������
	unsigned short GetLength(const char* str) const;
	void CopyStrs(char* dest, const char* source);
public:
	inline static char nochar = -1;
	char* c_str() { return cstr; }
	~hstring();

	hstring(char clen = 0x32);
	hstring(const char* str);						// ����C�ַ���������hstring
	hstring(const hstring& str);					// ����hstring������hstring
	hstring& operator=(const hstring& str);
	// hstring& operator=(const long long& value);  // ʵ��long long ���� ��ҵ1
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str);
	// bool ResetMemory(unsigned short);			// ��ҵ ���軺�����Ĵ�С
	// unsigned short GetMemory();					// ��ҵ ��ȡ��ǰ�������Ĵ�С
	// unsigend short GetLength();					// ��ҵ ��ȡ�ַ�������

	const char& operator[](const unsigned short index)const;

	const char& operator()();

	//��ȡ�ַ���
	hstring operator()(const unsigned short start, const unsigned short length) const;
};
std::ostream& operator<<(std::ostream& _cout, hstring& _str); //������������
std::istream& operator>>(std::istream& _cin, hstring& _str);  //������������
#endif