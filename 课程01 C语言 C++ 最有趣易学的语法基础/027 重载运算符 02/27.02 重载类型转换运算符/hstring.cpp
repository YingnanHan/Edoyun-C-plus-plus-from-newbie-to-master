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
	cstr = 0;
	if (clen > 0)
	{
		usmlen = clen;
		uslen = 1;
		cstr = new char[usmlen] {};
	}
}

//hstring::operator void* ()
//{
//	return cstr;
//}



hstring::hstring(int val) :hstring()
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
	// return *this;
}

hstring::hstring(const char* str) :hstring()	// ����C�ַ���������hstring
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

hstring& hstring::operator+(const hstring&& str)
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
		//�ַ�����ʼλ�ò�����
		return hstring("");
	}

	unsigned slen = start + length > uslen - 1 ? uslen - start - 1 : length;
	char* newstr = new char[slen + 1];
	memcpy(newstr, cstr + start, slen + 1);
	newstr[slen] = 0;
	return hstring(newstr);
}

hstring::operator bool()
{
	return cstr != nullptr;
}

bool hstring::operator==(std::nullptr_t nptr)
{
	return cstr == nptr;
}

std::ostream& operator<<(std::ostream& _cout, hstring& _str) //������������
{
	_cout << _str.c_str();
	return _cout;
}

std::ostream& operator<<(std::ostream& _cout, hstring&& _str) //������������
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

//hstring::operator int()
//{
//	//��ǰ���ַ��洢��cstr�м�
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