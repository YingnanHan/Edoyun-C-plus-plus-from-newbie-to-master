#include "Role.h"

void Role::Init() // 在外边编写函数必须限定作用域
{
	hpRecover = 3;
}

void Role::Act(Role& role) // 在外边编写函数必须限定作用域
{
	// hp = 2;
	role.hp -= damage;
}

Role* Role::bigger(Role* role)
{
	return role->lv > lv ? role : this;
}

Role& Role::SetLv(int newLv)
{
	lv = newLv;
	return *this;
}

Role& Role::SetHp(int newHp)
{
	hp = newHp;
	return *this;
}

Role& Role::SetDamage(int newDamage)
{
	damage = newDamage;
	return *this;
}

int Role::GetLv() const
{
	return lv;
}

int& Role::GetLv()
{
	return this->lv;
}

int Role::GetDamage() const //所有没有修改成员变量的函数一律要使用const修饰，否则const对象是用不了
{
	return damage;
}

int Role::GetDamage() // const对象调用的是const版本，非const对象调用的是非const版本
{
	return damage;
}