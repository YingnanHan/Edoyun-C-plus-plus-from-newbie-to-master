#include<iostream>

using namespace std;

// auto ave(int a, int b) // 定义使用了auto返回值类型的函数
int ave(int a, int b)
{
	return (a + b) / 2;
}

auto bigger(int& a, int& b) -> int& // auto& 返回值返回引用 一般情况下auto不加上&会直接返回值类型 
{	// 使用尾运算符也可以达到同样的效果
	return a > b ? a : b;
}

int main()
{
	//////////////////////////////////////////////////////////////////////
	auto a = 123; // 自动推断为int类型
	auto b{ a }; // 自动推断为int类型

	/*
		① auto会自动退掉cv运算符，不会保留const volatile属性
		② auto默认会将引用丢弃，将值优先推断为值类型
		③ auto作为函数的会返回类型的时候，函数会执行
	*/

	bigger(a, b) = 500; // 返回值是一个左值 将较大值修改为500
	//////////////////////////////////////////////////////////////////////
	decltype(a - b) x; // x的类型是int
	std::cout << a << " " << b << " " << typeid(bigger(a, b)).name() << std::endl;
	//////////////////////////////////////////////////////////////////////
	/*
		① decltype会保留cv运算符
		② 以及保留const属性，与auto正相反
		③ decltype会根据实际的运算结果推断类型
		④ 如果推断内容是左值那么结果是引用类型，反之是值类型
	*/
	decltype(a + b) x = a; // 如果decltype没有固定的内存地址，那么就会根据实际计算得出的结果类型推断参数的类型
	//////////////////////////////////////////////////////////////////////
	auto xauto = ave(a, b); // 推断的过程中会计算ave
	decltype(ave(a, b)) dauto = ave(a, b); // 推断的过程中不会执行表达式

	return 0;
}