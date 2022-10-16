#include<iostream>

extern void testX(); //LNK2019	无法解析的外部符号 "void __cdecl testX(void)" (? testX@@YAXXZ)，函数 main 中引用了该符号	23.04 LINK 2019	C:\Users\20613\Desktop\Edoyun - C - plus - plus - from - newbie - to - master\课程01 C语言 C++ 最有趣易学的语法基础\023 庖丁解牛 从编译器的角度来理解函数\23.04 LINK 2019\源.obj	1

int main()
{
	testX();
	return 0;
}
