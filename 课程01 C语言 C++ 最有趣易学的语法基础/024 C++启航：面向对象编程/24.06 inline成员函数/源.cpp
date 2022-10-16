#include<iostream>
#include"Role.h"

using namespace std;

void test(Role* p)
{
	p->SetHp(5000);
}

int main()
{
	// ① 不可以绕过成员变量通过成员函数来修改const变量
	
	const Role user{}; // user 的成员变量不可以被改变
	Role monster;
	const Role* puser{ &user }; //指针是一个const，所以该对象不可以改
	// puser->damage = 200; // 错误

	// ② 如果const类对象中存在const函数，那么就可以直接调用该函数，进行某一些变量的修改

	// const Role user; // user 的成员变量不可以被改变
	// Role monster;
	// const Role* puser{ &monster }; //指针是一个const，所以该对象不可以改
	//puser->damage = 200; // 错误
	puser->GetHP();
	monster.GetHP();

	// ③ const对象只能调用const成员函数

	monster.GetLv() = 200; // 返回一个引用并且是一个可以被修改的左值
	// 实际上并不推荐上面的那种写法，一般的话应该写成monster.SetLv(200);
	std::cout << monster.GetLv() << endl;;
	monster.SetDamage(100);
	std::cout << monster.GetDamage() << std::endl;

	// ④ 强制类型转换
	test((Role*)(&user)); // 方案一
	std::cout << puser->GetHP() << std::endl;
	test(const_cast<Role*>(&user)); // 方案二 防止传值传不进去
	std::cout << puser->GetHP();
	return 0;
}

/*
const原则：
	const对象不能以任何方式改变，这是const的原则，在这个基本原则下，产生了一系列效应，比如
	const对象只能调用const函数
	另外一个我们不注意的变化是，在const成员函数下，this指针也变成了const指针
*/