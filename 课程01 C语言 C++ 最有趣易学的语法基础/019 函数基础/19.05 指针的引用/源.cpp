#include<iostream>

typedef struct Role
{
	char Name[ 0x20 ];
	int hp;
	int mp;
	int damage;
}*PROLE;

// 如果需要在函数执行结束之后修改指针的指向
// 那么需要使用 *& 来定义一个指向引用的指针
bool Act(const Role& Actor, PROLE& beAct)
{
	beAct->hp -= Actor.damage;
	bool bEnd = beAct->hp < 0;
	beAct = (Role*)&Actor;// 交换攻击方
	return bEnd;
}

int main()
{
	Role user{ "奥特曼",200, 300, 850 };
	Role monster{ "小怪兽",800, 300, 50 };
	Role* pRole = &monster;

	if (Act(user, pRole))
	{
		std::cout << pRole->Name << "  怪物死亡，获取经验值:XXXXX";
	}
}