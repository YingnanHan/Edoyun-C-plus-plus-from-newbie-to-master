#include<iostream>

typedef struct Role
{
	char Name[ 0x20 ];
	int hp;
	int mp;
	int damage;
}*PROLE;

// �����Ҫ�ں���ִ�н���֮���޸�ָ���ָ��
// ��ô��Ҫʹ�� *& ������һ��ָ�����õ�ָ��
bool Act(const Role& Actor, PROLE& beAct)
{
	beAct->hp -= Actor.damage;
	bool bEnd = beAct->hp < 0;
	beAct = (Role*)&Actor;// ����������
	return bEnd;
}

int main()
{
	Role user{ "������",200, 300, 850 };
	Role monster{ "С����",800, 300, 50 };
	Role* pRole = &monster;

	if (Act(user, pRole))
	{
		std::cout << pRole->Name << "  ������������ȡ����ֵ:XXXXX";
	}
}