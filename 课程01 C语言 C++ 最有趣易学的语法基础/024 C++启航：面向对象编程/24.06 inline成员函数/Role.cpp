#include "Role.h"

void Role::Init() // ����߱�д���������޶�������
{
	hpRecover = 3;
}

void Role::Act(Role& role) // ����߱�д���������޶�������
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

int Role::GetDamage() const //����û���޸ĳ�Ա�����ĺ���һ��Ҫʹ��const���Σ�����const�������ò���
{
	return damage;
}

int Role::GetDamage() // const������õ���const�汾����const������õ��Ƿ�const�汾
{
	return damage;
}