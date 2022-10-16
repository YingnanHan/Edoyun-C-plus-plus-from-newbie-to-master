#include<iostream>

using namespace std;

const int SCREEN_WIDTH = 1980;
#define int float
#define true false // define的缺点
#define X //如果X被定义那么X会被替换为空字符

// define也可以用来做标记，尤其是在一些WindowsAPI当中，用来做提示
#define _int_
#define _out_
#define _TEST_ //这类定义不可一起和其他标识符不加空格的连用

int ave(_int_ int a, _out_ int& b)
{
	return a / 2 + b / 2;
}

int main()
{
	int _TEST_ _a{ 250 };
#undef _TEST_ //取消使用_TEST_宏,后面就不可以再用_TEST_标识符，值得注意的是，删除顺序是编译顺序而不是函数执行顺序
	// int _TEST_ _b{ 250 }; // 错误
	return 0;
}
