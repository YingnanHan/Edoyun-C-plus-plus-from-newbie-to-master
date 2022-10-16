#include<iostream>

extern "C"
{
	#include"e.h" // 将头文件中的所有内容以C语言的模式编译
}


using namespace std;

// 本程序可以编译通过是因为C++再编译函数的时候考虑到了重载，一个函数在编译的时候
// 函数名字被修改过了，所以.c文件中的ave与.cpp中的ave实际上在内存中并不相同

// 将C++函数生命成为C风格函数
extern "C" void hello()
{
	std::cout << "Hello" << endl;
}

int main()
{
	return 0;
}