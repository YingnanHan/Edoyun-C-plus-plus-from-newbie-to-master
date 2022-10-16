#include<iostream>

/*emplate<typename TR=int, typename T1, typename T2>
TR ave(T1 a, T2 b)
{
	return (a + b) / 2;
}*/

//template<typename TR = int, typename T1 = TR, typename T2> // 默认模板类型参数
//TR ave(T1 a, T2 b)
//{
//	return (a + b) / 2;
//}

// 默认模板参数 -- 函数模板可以有非类型的模板参数
template<int max = 2000, int min = 1000, typename T>
bool ChangeHp(T& hp, T damage)
{
	hp -= damage;
	if (hp > max)
	{
		hp = max;
	}
	return hp < min;
}


int main()
{
	int hp = 2500;
	ChangeHp<2000, 1000>(hp, 100); // 有参数推断T类型， 传递的<>内部的参数作为模板常数参数，实质上就是模板替换
	std::cout << hp;
	return 0;
}