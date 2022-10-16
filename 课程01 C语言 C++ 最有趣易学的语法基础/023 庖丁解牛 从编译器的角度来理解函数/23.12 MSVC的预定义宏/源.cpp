#include<iostream>

using namespace std;

int ave(int a, int b)
{
	std::cout << __func__ << std::endl;
	std::cout << __FUNCTION__ << std::endl; //返回函数名称
	std::cout << __FUNCDNAME__ << std::endl;//返回函数编译后的名称 专门应对C++重载问题的
	std::cout << __FUNCSIG__ << std::endl;//获取函数的调用方式 传参方式
	return 0;
}

int main()
{
#ifdef _CHAR_UNSIGNED // 如果char类型为无符号则该宏为1
	std::cout << "_CHAR_UNSIGNED";
#endif

	// __COUNTER__用于计数，调用一次它的值加一

#ifdef _DEBUG
	// 用于调试模式
#endif
	ave(1,1);
	return 0;
}