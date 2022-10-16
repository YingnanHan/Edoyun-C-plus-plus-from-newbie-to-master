#include<iostream>

using namespace std;


template<typename T1, typename T2>
T1 ave(T2 a, T1 b)
{
	return (a + b) / 2;
}

template<typename T1, typename T2, typename T3>
T3 ave(T1 a, T2 b, int c=10) // 可以加上其他的固定参数，它含有确定的类型
{
	return (a + b) / 2;
}

int main()
{
	//cout << ave(100, 200);
	//cout<<ave<double, double>(100, 200.0); // 强制指定模板函数参数类型

	std::cout << ave<int, float, double>(100, 1); //这里由于只有两个可供类型推断的参数，所以如果不指定参数类型，编译器将无法推断模板函数

	return 0;
}
