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

	bool Act(NPC* beactor)
	{
		beactor->hp -= damage;
		return beactor->hp > 0;
	}
};


int main()
{
	MONSTER atm{ 1000, 500, 100, 6000 };
	ROLE zs{ 1000, 1000, 50, 1000 };
	ROLE ls{ 1000, 500, 100, 6000 };

	zs.Act((NPC*)&ls);
	std::cout << ls.hp;

	return 0;
}