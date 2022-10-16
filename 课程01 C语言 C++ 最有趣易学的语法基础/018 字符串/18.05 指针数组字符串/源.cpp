#include<iostream>
#include<string>

using namespace std;

int main()
{
	// case 01
	//string str1{ "12345" };
	//std::cout << str1[0] << endl;
	//// 字符串可以使用下标来取到其中的内容
	//// 由于string是一个对象，并且根据内部的字符串重载
	//// 所以 (int)&str1 != (int)&str1[0]
	//std::cout << (int)&str1 << " " << (int)&str1[0] << std::endl;

	//str1 = str1 + "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//std::cout << (int)&str1 << " " << (int)&str1[0] << std::endl;

	//// 通过上面的对比 可以发现 string类对象一旦定义其内存地址不会发生变化
	//// 其中的内容具体是存在何处由操作系统确定，当字符串的长度发生过大变化
	//// 的时候，原来存放字符串的空间被释放，并且开辟一块新的空间进行存储更
	//// 新过后的字符串原来的字符串对象中定义的str变量指向的位置发生变化但是
	//// 它本身并没发生地址层面的任何改动



	// case 02 使用c_str()来查找字符串实际存放的地址
	//string str{ "12345" };
	//std::cout << str[0] << std::endl;

	//std::cout << (int)&str << " " << (int)&str[0] << " "<<(int)&str[1] << std::endl;
	//str = str + "655555555555535";
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << std::endl;
	//
	//const char* baseStr = str.c_str(); //返回实际的string字符串
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << " " << int(baseStr) << std::endl;
	//// c_str() 返回C风格字符串， 但是返回类型是const所以不可以修改 可以const_cast进行强制修改



	// case 03 使用data()来查找字符串实际存放的地址并且得到一个可以修改的字符串 char类型的指针  C++ 17

	//string str{ "12345" };
	//std::cout << str[0] << std::endl;

	//std::cout << (int)&str << " " << (int)&str[0] << " "<<(int)&str[1] << std::endl;
	//str = str + "655555555555535";
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << std::endl;
	//
	//char* baseStr = str.data(); //返回实际的string字符串
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << " " << int(baseStr) << std::endl;



	// case 04
	// C++11之后 字符串的末尾也被定义成'\0'



	// case 05 replace() 替换函数
	/*string stdID{ "id=user" };
	stdID.replace(3, 4, 6, '*');
	std::cout << stdID << std::endl;
	stdID.replace(3, 4, "张三");
	std::cout << stdID << std::endl;
	stdID.replace(3, 4, "zhangsanpkq", 3, 4);
	std::cout << stdID << std::endl;*/

	// case 06 插入函数 insert
	// case 07 擦除函数 erase

	// 用法同上

	return 0;
}