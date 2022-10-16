#include<iostream>
#include<string>

using std::string;

int main()
{
	/*
	// C原生字符串
	char str[0x10] = "123";
	char strB[0x10] = "456";

	char strC[0x20];
	memcpy(strC, str, strlen(str));
	memcpy(strC + strlen(str), strB, strlen(strB) + 1);
	*/

	// C++字符串
	string str1("吃葡萄不吐葡萄皮!! ass"); // 初始化方式①
	//std::cin >> str;
	//std::cout << str;
	string str2("你好啊！", 3); // 初始化方式② 从某一个位置开始截取字符串
	string str3("56789", 2, 3); // 初始化方式③ 截取某一段字符串
	string str4(str1, 0, 6); // 初始化方式④ 截取某一段字符串
	string str5(6, 'a'); // 初始化方式⑤ 设置字符串具有多少个同样的字符

	// 字符串的连接
	string str = "123" + string(" ") + "456"; // 默认情况下 直接定义字符串作为字面量默认是const char* 类型 所以这里应该使用至少一个string进行类型转换导致结果生成时执行隐式转换
	int age;
	std::cin >> age;
	string ls = "用户的年龄是:" + std::to_string(age); // 如果不转换为string那么就会按照字节为单位解释成一个个ASCII码对应的字符
	std::cout << ls;

	return 0;
}