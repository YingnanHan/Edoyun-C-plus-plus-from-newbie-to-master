#include<iostream>
#include"hstring.h"

using namespace std;

int main()
{
	// 01 上节测试
	//hstring str = "a123";
	//hstring xstr = str(1, 2);
	//std::cout << xstr << str(1, 2);;

	// 02 将数字转换成字符串
	
	/*unsigned int val = -1;
	char str[12]{};
	char strR[12]{};
	int len{};
	bool bfs = val < 0;

	if (bfs)
	{
		val = -1 * val;
	}

	do
	{
		str[len++] = val % 10 + 48;
		val = val / 10;
	} while (val);

	if (bfs)
	{
		str[len++] = '-';
	}

	for (int i = 0; str[i]; i++)
	{
		strR[i] = str[len - i - 1];
	}

	cout << strR;*/

	// 03 将数字转换成字符串

	/*unsigned int val = 0;
	char str[12]{};
	char strR[12]{};
	int len{11};
	bool bfs = val < 0;

	if (bfs)
	{
		val = -1 * val;
	}

	do
	{
		str[--len] = val % 10 + 48;
		val = val / 10;
	} while (val);

	if (bfs)
	{
		str[len++] = '-';
	}

	cout << &str[len];*/

	// 04 将数字转换成字符串
	/*int val = 123123123;
	char str[12]{};
	int len{ 11 };
	bool bzs = val >= 0;
	val = val * (bzs * 2 - 1);

	do
	{
		str[--len] = val % 10 + 48;
	} while (val = val / 10);

	if (!bzs)
	{
		str[--len] = '-';
	}

	cout << &str[len]; */

	// 05 将数字转换成字符串

	/*int val = -123123123;
	char str[0x20]{};
	int len{ 0x1F };
	bool bzs = val >= 0;
	val = val * (bzs * 2 - 1);

	do
	{
		str[--len] = val % 10 + 48;
	} while (val = val / 10);

	str[len = len - 1 * (1 - bzs)] = '-' * (bzs + 1) * (1 - bzs) + str[len] * bzs;

	cout << &str[len];*/

	// 06
	hstring str = "123abc";
	str = str + 123456 + (unsigned)-1;
	std::cout << str;

	return 0;
}