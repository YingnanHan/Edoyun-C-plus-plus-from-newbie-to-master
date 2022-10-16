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

	bool Act(NPC* beactor)
	{
		beactor->hp -= damage;
		return beactor->hp > 0;
	}

	void Init()
	{
		hpRecover = 3;
	}
private:
	int hpRecover;
public:
	int damage;
	int diamond;
private:
	unsigned dtime;
};

int main()
{
	CROLE zs;// { 1000, 1000, 50, 1000 };
	CROLE ls;// { 1000, 500, 100, 6000 };
	
	zs.Init(); //封装 保护数据安全
	ls.Init();

	zs.Act((NPC*)&ls);
	std::cout << ls.hp; //对象中多个数据成员被默认初始化为0

	return 0;
}