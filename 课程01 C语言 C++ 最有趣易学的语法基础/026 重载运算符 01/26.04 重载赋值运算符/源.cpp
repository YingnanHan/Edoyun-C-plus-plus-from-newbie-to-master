#include<iostream>

using namespace std;

class Role
{
public:
	int hp;
	int mp;

	Role& operator=(const Role& role) // 必须为成员函数
	{
		hp = role.hp;
		mp = role.mp;
		return *this; // 返回引用
	}
};

class hstring1
{
	unsigned short usmlen;	// 字符串的内存长度
	char* cstr;			// 字符串的长度
	unsigned short uslen;	// 字符串的内容
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
	// 自定义实现类型转换复制重载运算符
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
		cstr = new char[len]; // 重新分配内存
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len; //字符串长度修正
}

hstring1::hstring1(const char* str):hstring1()	// 利用C字符串来构造hstring1
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

	z = y = x; // 浅拷贝 Role& operator=(const Role& role); 被调用

	std::cout << y.hp << " ///// " << y.mp; 

	char strA[] = "你好易道云";
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