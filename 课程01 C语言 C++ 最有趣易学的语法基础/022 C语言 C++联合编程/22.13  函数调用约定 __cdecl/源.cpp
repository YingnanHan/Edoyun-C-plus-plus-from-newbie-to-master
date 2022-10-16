#include<iostream>

using namespace std;

double __cdecl ave(double a, double b)
{
	return (a + b) / 2;
}

int main()
{
	// __cdecl 参数入栈顺序 从左到右 堆栈平衡 谁调用谁平衡 意思就是由调用函数来平衡
	// 参数的出入栈，可以支持不定量参数
	cout << ave(1, 2);
	return 0;
}