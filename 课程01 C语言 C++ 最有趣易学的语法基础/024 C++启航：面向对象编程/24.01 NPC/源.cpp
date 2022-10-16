#include<iostream>

struct NPC
{
	int hp;
	int mp;
	int damage;
};

struct MONSTER
{
	int hp;
	int mp;
	int damage;
	int price;
};

struct ROLE
{
	int hp;
	int mp;
	int damage;
	int diamond;
};

bool Act(NPC* actor, NPC* beactor)
{
	beactor->hp -= actor->damage;
	return beactor->hp > 0;
}

int main()
{
	MONSTER atm{1000, 500, 100, 6000};
	ROLE zs{ 1000, 1000, 50, 1000 };
	ROLE ls{1000, 500, 100, 6000};

	/*Act((NPC*)&zs, (NPC*)&ls);*/
	Act((NPC*)&atm, (NPC*)&ls);
	std::cout << ls.hp;
	return 0;
}