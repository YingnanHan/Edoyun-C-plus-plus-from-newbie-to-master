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

	// hstring();
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
		// ƴ��
		unsigned short slen = uslen + 0x20 - len - 1;
		if (slen > usmlen)
		{
			char* lstr = cstr;
			cstr = new char[slen] {}; // ���·����ڴ�
			usmlen = slen;//�����ڴ�ĳ���
			memcpy(cstr, lstr, uslen);
			delete[] lstr; // ɾ���ڴ�
		}

		memcpy(cstr + uslen - 1, str + len, 0x20 - len);
		uslen = slen; //�ַ�����������
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
		// ƴ��
		unsigned short slen = uslen + 0x20 - len - 1;
		if (slen > usmlen)
		{
			char* lstr = cstr;
			cstr = new char[slen] {}; // ���·����ڴ�
			usmlen = slen;//�����ڴ�ĳ���
			memcpy(cstr, lstr, uslen);
			delete[] lstr; // ɾ���ڴ�
		}

		memcpy(cstr + uslen - 1, str + len, 0x20 - len);
		uslen = slen; //�ַ�����������
		return *this;
	}

	operator int()
	{
		short val{ 0 };
		int i = cstr[0] == '-'; //���
		while (cstr[i] >= '0' && cstr[i] <= '9')
		{
			val = val * 10 + cstr[i++] - 48;
		}
		val = val * ((cstr[0] != '-') * 2 - 1); // ����Ǹ������ɸ���

		return val;
	}
};
std::ostream& operator<<(std::ostream& _cout, hstring& _str); //������������
std::ostream& operator<<(std::ostream& _cout, hstring&& _str); //������������,�ӳ���������
std::istream& operator>>(std::istream& _cin, hstring& _str);  //������������
#endif