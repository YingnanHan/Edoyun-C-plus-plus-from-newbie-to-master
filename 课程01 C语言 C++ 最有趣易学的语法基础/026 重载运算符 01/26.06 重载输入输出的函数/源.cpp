#include<iostream>
#include"hstring.h"

using namespace std;

int main()
{
	// 01
	/*hstring str{"´ó¼ÒºÃÑ½"};
	hstring str1{ "@@@/" };
	str << "1123" <<"213323412";
	cout << str.c_str();
	cout << endl;
	str + "1123" + "213323412";
	cout << str.c_str();*/

	// 02
	/*hstring str{ "hello" };
	cout << str;*/

	//03
	hstring str;
	cin >> str;
	cout << str;
	return 0;
}