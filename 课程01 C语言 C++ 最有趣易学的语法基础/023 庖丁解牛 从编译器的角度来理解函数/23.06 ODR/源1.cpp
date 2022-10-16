#include<iostream>

static int a = 350;
extern const int pt = 1000; // 将内部链接属性使用extern转化为外部链接属性
extern int x;

static void Test() // 使用static会导致Test具有内部链接属性
{
	std::cout << "Test";
}