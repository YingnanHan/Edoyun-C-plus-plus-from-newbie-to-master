#pragma once

#include<iostream>

using namespace std;

//列表变量初始化的顺序是变量定义的顺序
class Role
{
private:
	int hpRecover;
	void Init(); // 需要在外部定义的函数必须要先在类内部声明
	int hp;
public:
	//Role() // 自定义默认构造函数
	//{
	//	//std::cout << "自定义默认构造函数" << std::endl;
	//}

	bool IsBig(Role rl)
	{
		return rl.GetLv() > lv;
	}

	Role(const Role& role) : hp(role.hp) //副本构造函数的初始化部分可以访问私有化成员
	{
		// 副本构造函数初始化的时候仅仅初始化被指定的内容
		// 同一类中是可以访问同一类类型作为参数的私有变量
	}

	// 委托构造函数只可以使用一次，并且其他变量未初始化的部分需要在函数内部进行
	Role(int _lv, int damage) : Role(_lv) // 使用成员初始化列表,在函数执行之前就已经将值初始化
	{
		this->damage =  damage ;
		std::cout << "lv:" << lv << " " << "damage:" << damage << std::endl;
	}

	Role() = default; // 自定义默认构造函数 better

	explicit Role(int _lv)  // 自定义构造函数 注意这里的参数不可以是默认参数否则会导致歧义
	{
		lv = _lv;
	}

	int lv;
	int damage;

	void Act(Role& role); // 需要在外部定义的函数必须要先在类内部声明

	inline int GetHP() const // 内联函数推荐写在头文件里 加上const关键字的话就可以在const指针下使用该函数
	{
		// this->hp = 2; // 错误：表达式必须是可修改的左值
		return hp;
	}

	Role* bigger(Role* role);
	Role& SetLv(int newLv);
	Role& SetHp(int newHp);
	Role& SetDamage(int newDamage);

	int GetLv() const;
	//int& GetLv() const; // 这里的函数不可以编译，语法上是矛盾的 或者为了编译通过使得这个函数返回值变为const int&,当然这样做会导致main()_函数里面的调用失败
	int& GetLv();

	int GetDamage() const;
	int GetDamage();
};