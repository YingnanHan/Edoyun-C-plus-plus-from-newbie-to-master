#include<iostream>

using namespace std;

int ave(int a, int b)
{
	return 0.5 * (a + b);
}

//int ave(const int a, const int b) // 形同虚设 因为传进来的参数都是拷贝,常量也可以被变量初始化
//{
//	return 0.5 * (a + b);
//}

int main()
{
	ave(100, 100);
	return 0;
}