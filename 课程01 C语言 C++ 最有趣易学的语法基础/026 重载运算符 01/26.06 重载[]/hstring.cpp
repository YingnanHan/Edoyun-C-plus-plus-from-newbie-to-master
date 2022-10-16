#include"hstring.h"

unsigned short hstring::GetLength(const char* str) const
{
	unsigned short len = 0;
	for (; str[len++];);
	return len;
}

void hstring::CopyStrs(char* dest, const char* source)
{
	unsigned short len = GetLength(source);
	if (len > usmlen)
	{
		// �����ڴ�й©����
		delete[] cstr;
		cstr = new char[len]; // ���·����ڴ�
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len; //�ַ�����������
}



hstring::~hstring()
{
	if (cstr != nullptr) delete[] cstr;
}

hstring::hstring(char clen)
{
	usmlen = clen;
	uslen = 0;
	cstr = new char[usmlen];
}



hstring::hstring(const char* str) :hstring()	// ����C�ַ���������hstring
{
	CopyStrs(cstr, str);
}

hstring::hstring(const hstring& str):hstring()	// 
{
	CopyStrs(cstr, str.cstr);
}

hstring& hstring::operator=(const hstring& str)
{
	CopyStrs(cstr, str.cstr);
	return *this;
}

hstring& hstring::operator<<(const hstring& str)
{
	unsigned short slen = GetLength(str.cstr);
	slen = uslen + slen - 1;
	if (slen > usmlen)
	{
		char* lstr = cstr;
		cstr = new char[slen]; // ���·����ڴ�
		usmlen = slen;//�����ڴ�ĳ���
		memcpy(cstr, lstr, uslen);
		delete[] cstr; // ɾ���ڴ�
	}

	memcpy(cstr + uslen - 1, str.cstr, slen - uslen + 1);
	uslen = slen; //�ַ�����������

	return *this;
}

hstring& hstring::operator+(const hstring& str)
{
	return *this << str;
}

const char& hstring::operator[](const unsigned short index) const
{
	if (index > uslen)
		return hstring::nochar;
	else
		return cstr[index];
}

std::ostream& operator<<(std::ostream& _cout, hstring& _str) //������������
{
	_cout << _str.c_str();
	return _cout;
}

std::istream& operator>>(std::istream& _cin, hstring& _str) //������������
{
	char _sRead[0x1FF]{};
	_cin >> _sRead;
	_str = _sRead;
	return _cin;
}

//hstring& hstring::operator=(const char* str)
//{
//	CopyStrs(cstr, str);
//	return *this;
//}