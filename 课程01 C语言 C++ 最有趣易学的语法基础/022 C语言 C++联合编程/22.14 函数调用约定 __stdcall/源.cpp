#include<iostream>

using namespace std;

double __stdcall ave(double a, double b)
{
	return (a + b) / 2;
}

int main()
{
	//__stacall参数入栈顺序 从左到右
	// 堆栈平衡:函数自己恢复栈平衡
	// Windows 编程中WINAPI CALLBACK 都是__stdcall的宏
	// 生成的函数名字会加下划线，后面跟@和参数尺寸
	cout << ave(1, 2);
	return 0;
}