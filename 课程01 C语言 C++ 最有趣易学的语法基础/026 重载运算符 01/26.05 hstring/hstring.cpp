#include"hstring.h"
#include "../26.06 重载[]/hstring.h"

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
		// 存在内存泄漏问题
		delete[] cstr;
		cstr = new char[len]; // 重新分配内存
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len; //字符串长度修正
}



hstring::hstring(const char* str) :hstring()	// 利用C字符串来构造hstring
{
	CopyStrs(cstr, str);
}



hstring::hstring(const hstring& str)	// 
{
	CopyStrs(cstr, str.cstr);
}

hstring& hstring::operator=(const hstring& str)
{
	CopyStrs(cstr, str.cstr);
	return *this;
}

hstring& hstring::operator=(const char* str)
{
	CopyStrs(cstr, str);
	return *this;
}

hstring& hstring::operator<<(const hstring& str)
{
	unsigned short slen = GetLength(str.cstr);
	slen = uslen + slen - 1;
	if (slen > usmlen)
	{
		delete[] cstr; // 删除内存
		cstr = new char[slen]; // 重新分配内存
		usmlen = slen;//修正内存的长度
	}

	memcpy(cstr + uslen - 1, str.cstr, slen - uslen+1);
	uslen = slen;

	return *this;
}

hstring& hstring::operator+(const hstring& str)
{
	return *this << str;
}


std::ostream& operator<<(std::ostream& _cout, hstring& _str) //输出运算符重载
{
	_cout << _str.c_str();
	return _cout;
}

char hstring::operator[](const unsigned short index) const
{
	return cstr[index];
}

std::istream& operator>>(std::istream& _cin, hstring& _str) //输出运算符重载
{
	char _sRead[0x1FF]{};
	_cin >> _sRead;
	_str = _sRead;
	return _cin;
}