#include<iostream>

using namespace std;

class Role
{
public:
	int hp;
	int mp;

	Role& operator=(const Role& role) // ����Ϊ��Ա����
	{
		hp = role.hp;
		mp = role.mp;
		return *this; // ��������
	}
};

class hstring1
{
	unsigned short usmlen;	// �ַ������ڴ泤��
	char* cstr;			// �ַ����ĳ���
	unsigned short uslen;	// �ַ���������
	unsigned short GetLength(const char* str) const;

	void CopyStr(char* dest, const char* source);
public:
	char* c_str()
	{
		return cstr;
	}
	hstring1();
	hstring1(const char* str);
	hstring1(const hstring1& str);
	hstring1& operator=(const hstring1& str);
	hstring1& operator=(const char* str);
	// �Զ���ʵ������ת���������������
	hstring1& operator=(const int& value);
	hstring1& operator=(const float& value);
	hstring1& operator=(const long long& value);
};

unsigned short hstring1::GetLength(const char* str) const
{
	unsigned short len = 0;
	for (; str[len++];);
	return len;
}

void hstring1::CopyStr(char* dest, const char* source)
{
	unsigned short len = GetLength(source);
	if (len > usmlen)
	{
		cstr = new char[len]; // ���·����ڴ�
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len; //�ַ�����������
}

hstring1::hstring1(const char* str):hstring1()	// ����C�ַ���������hstring1
{
	CopyStr(cstr, str);
}

hstring1::hstring1()
{
	usmlen = 0x32;
	uslen = 0;
	cstr = new char[usmlen];
}

hstring1::hstring1(const hstring1& str)	// 
{
	CopyStr(cstr, str.cstr);
}

hstring1& hstring1::operator=(const hstring1& str)
{
	CopyStr(cstr, str.cstr);
	return *this;
}

hstring1& hstring1::operator=(const char* str)
{
	CopyStr(cstr, str);
	return *this;
}

int main()
{
	Role x, y, z;
	x.hp = 100;
	x.mp = 200;

	z = y = x; // ǳ���� Role& operator=(const Role& role); ������

	std::cout << y.hp << " ///// " << y.mp; 

	char strA[] = "����׵���";
	hstring1 str(strA);
	hstring1 str1(str);
	hstring1 str2{ "hello!" };

	strA[0] = 0;
	std::cout << str.c_str() << endl;
	std::cout << str1.c_str() << endl;

	str1 = str2;
	str1 = "1111";

	return 0;
}