#include<iostream>

using namespace std;

int add(int& a, int& b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 0;
	int b = 9;
	cout << add(1, 1); 
	// cout << add(a, b) << endl; //错误(活动)	E0308	有多个 重载函数 "add" 实例与参数列表匹配:	21.03 引用与值传递同时重载会出错的情况	C : \Users\20613\Desktop\易道云 C++ 全栈 工程\课程01 C语言 C++ 最有趣易学的语法基础\021 函数重载与函数模板\21.03 引用与值传递同时重载会出错的情况\源.cpp	20

}
