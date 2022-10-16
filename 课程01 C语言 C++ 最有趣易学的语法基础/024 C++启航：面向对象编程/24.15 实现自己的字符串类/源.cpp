#include<iostream>

using namespace std;

class hstring
{
private:
	char* c_str;
	unsigned short len;
	unsigned short length(const char* str)
	{
		unsigned short len{ 0 };
		while (str[len++]);
		return len;
	}
public:
	hstring()
	{
		len = 0;
		c_str = new char[1] {0};
	}

	hstring(const char* str)
	{
		len = length(str);
		c_str = new char[len];
		memcpy(c_str, str, len);
	}

	char* Show() const
	{
		return c_str;
	}

	~hstring()
	{
		delete[] c_str;
	}

	hstring(const hstring& hstr) : hstring(hstr.Show()) // 不建议这么写
	{

	}

	void SetStr(const char* str)
	{
		delete c_str;
		len = length(str);
		c_str = new char[len];
		memcpy(c_str, str, len);
	}
};

int main()
{
	hstring str("hello");
	hstring strA(str);
	str.SetStr("\nending");
	std::cout << strA.Show() << std::endl;
	std::cout << str.Show() << std::endl;
	return 0;
}
