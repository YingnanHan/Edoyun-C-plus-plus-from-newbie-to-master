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
		// 存在内存泄漏问题
		delete[] cstr;
		cstr = new char[len]; // 重新分配内存
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len; //字符串长度修正
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



hstring::hstring(const char* str) :hstring()	// 利用C字符串来构造hstring
{
	CopyStrs(cstr, str);
}

hstring::hstring(const hstring& str) :hstring()	// 
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
		cstr = new char[slen]; // 重新分配内存
		usmlen = slen;//修正内存的长度
		memcpy(cstr, lstr, uslen);
		delete[] cstr; // 删除内存
	}

	memcpy(cstr + uslen - 1, str.cstr, slen - uslen + 1);
	uslen = slen; //字符串长度修正

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


const char& hstring::operator()()
{
	return cstr[0];
}

hstring hstring::operator()(const unsigned short start, const unsigned short length) const
{
	//"123"
	//uslen = 4
	//2,1 = 3
	//2,2 = 3

	if (start > uslen - 2)
	{
		//字符串起始位置不合理
		return hstring("");
	}

	unsigned slen = start + length > uslen - 1 ? uslen - start - 1 : length;
	char* newstr = new char[slen + 1];
	memcpy(newstr, cstr + start, slen + 1);
	newstr[slen] = 0;
	return hstring(newstr);
}

std::ostream& operator<<(std::ostream& _cout, hstring& _str) //输出运算符重载
{
	_cout << _str.c_str();
	return _cout;
}

std::ostream& operator<<(std::ostream& _cout, hstring&& _str) //输出运算符重载
{
	_cout << _str.c_str();
	return _cout;
}

std::istream& operator>>(std::istream& _cin, hstring& _str) //输出运算符重载
{
	char _sRead[0x1FF]{};
	_cin >> _sRead;
	_str = _sRead;
	return _cin;
}

//hstring::operator int()
//{
//	//当前的字符存储在cstr中间
//
//}

//hstring& hstring::operator=(const char* str)
//{
//	CopyStrs(cstr, str);
//	return *this;
//}

/*string::hstring()
{
	uslen = 0;
	usmlen = 0;
	cstr = new char[0];
}*/