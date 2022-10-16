/*
	定义在函数内的类称为局部类
	(1) 局部类必须定义在类内
	(2) 局部类中不允许使用静态成员变量
	(3) 局部类可以访问全局变量
*/

#include<iostream>

using namespace std;

int main()
{
	class T // 局部类 -- 可以使用全局变量但是不可以使用局部变量
	{
		int hp;
		int mp;

	public:
		 
		auto GetHP()
		{
			return this->hp;
		}

		static int GetCount()
		{
			// 可以定义静态函数但是不可以定义静态变量
		}

	};

	T t1;

	return 0;
}