#include<iostream>

template<typename T1, typename T2>
// auto bigger(T1 &a, T2 &b) -> decltype(a > b ? a : b)
decltype(auto) bigger(T1 &a, T2& b)
{// 如果需要强制指定返回类型那么就需要加上decltype
	return a > b ? a : b;
}

int main()
{
	char a = 10;
	int b = 500;
	std::cout << bigger(a, b); //原则上decltype返回的是引用类型，但是在这里传入的参数的两个类型不一样为了保存精度不丢失，这里就没有使用引用
}