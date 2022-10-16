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

class CROLE
{
public:
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
	CROLE zs{1000, 1000, 50, 1000};
	CROLE ls{1000, 500, 100, 6000};

	std::cout << ls.hp;

	return 0;
}