#include<iostream>
/*
	 嵌套类可以访问外层类的所有成员
	 外层类仅能访问嵌套类的公有成员
*/
using namespace std;

enum class WeaponLv // 枚举类型可以放到类的public里面
{
	normal = 0,
	high,
	rare,
	myth
};

class Role
{
public:
	static void test()
	{

	}
	Role()
	{
		Weapon::test1(); // 外层函数仅可以通过作用域解析运算符来查找内部类静态public修饰的成员
	}
	class Weapon
	{
		Weapon* ReturnW();
	public:
		static void test1()
		{

		}
		Weapon()
		{
			test(); //内层嵌套类可以访问外层静态函数/成员
		}
		short lv;
		WeaponLv wlv;
	};
	int hp;
	int mp;
	// Weapon leftHands;
};

//Role::Weapon::Weapon()
//{
//	std::cout << "weapon";
//}

Role::Weapon* Role::Weapon::ReturnW()
{
	return this;
}

int main()
{
	Role rl;
	Role::Weapon wpl;

	return 0;
}