#include<iostream>

using namespace std;

int __fastcall ave(int a, int b) // 使用寄存器来传递参数
{
	return (a + b) / 2;
}

int main()
{
	cout << ave(1, 2);
	// 00007FF7BD41187B  mov         edx, 2
	// 00007FF7BD411880  mov         ecx, 1
	return 0;
}

/*
第一个参数通过ecx传递
第二个参数通过edx传递
剩余参数入栈顺序 从右到左
堆栈平衡：函数自己恢复栈平衡
fastcall的函数执行速度比较快
*/