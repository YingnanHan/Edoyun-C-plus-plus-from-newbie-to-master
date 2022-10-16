


#include<iostream>
#include<string>

using namespace std;

int main()
{
	// case 01
	//// 设计一个程序，用户输入属性id或者pass或者role可以把其对应的内容显示出来
	//string str{ "id=user;pass=632105;role=郝英俊;" };
	//string strIn;
	//string strOut;

	//while(true)
	//{
	//	std::cout << "请输入您要查找的属性:\n";
	//	std::cin >> strIn; //要输入的字符串 属性
	//	int lfind = str.find(strIn + "=");
	//	if (lfind == std::string::npos)
	//	{
	//		std::cout << "对不起 您要查询的属性不存在!";
	//	}
	//	else
	//	{
	//		int lend = str.find(";", lfind);
	//		strOut = str.substr(lfind + strIn.length() + 1, lend - lfind - strIn.length()-1);
	//		std::cout << strOut << std::endl;
	//	}
	//}

	// case 02 字符串插入
	string id = "id=;";

	id.insert(3, "killertestid", 6);
	std::cout << id << std::endl;

	id.insert(3, "killertestid", 6, 6);
	std::cout << id << std::endl;

	id.insert(3, 6, '*');
	std::cout << id << std::endl;

	id.insert(3, "testid");
	std::cout << id << std::endl;

	return 0;
}
