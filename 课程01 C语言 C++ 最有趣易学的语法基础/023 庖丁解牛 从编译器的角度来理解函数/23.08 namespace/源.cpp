#include<iostream>

using namespace std;

namespace t
{
	int value;
}

using namespace t; // 在全局导入t命名空间中的变量或函数声明

int p{}; // 如果没明写，那么变量属于全局命名空间 具有外部连接属性
const int q{}; // 具有内部连接属性
int x = 2000;  // 具有外部连接属性
extern void test();

namespace t //对命名空间的扩展，可以用来扩展库
{
	int height{1250};
}

int main()
{
	t::value = 255;
	cout << "Hello World!" << endl;
	int p{};
	::p = 100; // 访问的是全局命名空间中的p
	test();
	return 0;
}