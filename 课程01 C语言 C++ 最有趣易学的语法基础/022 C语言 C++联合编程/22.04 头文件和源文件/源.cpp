#include<iostream>
#include"emath.h" // 头文件不会主动编译 只是内容上的完整替换 编译的仅仅是源文件，头文件被编译当且仅当被包含

using namespace std;

// 导入外部函数 方案①
//// 如果不添加头文件，而且需要从源文件中找到函数定义，那么就需要使用extern关键字声明函数的来源在本文件外部
//extern int ave(int a, int b); // 生明由外部文件而来的函数
//extern int bigger(int a, int b); // 生明由外部文件而来的函数

int main()
{
	cout << ave(1, 1) << std::endl;
	cout << bigger(1, 2) << std::endl;
	cout << account << endl;


	return 0;
}