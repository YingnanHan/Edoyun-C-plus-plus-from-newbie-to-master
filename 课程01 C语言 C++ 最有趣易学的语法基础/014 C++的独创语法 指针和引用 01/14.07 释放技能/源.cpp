#include<iostream>
#include<conio.h>

using namespace std;

struct Role
{
	int Hp;
	int MaxHp;
	int Mp;
	int MaxMp;
	int act;
	int cantact;  // 禁止攻击
	int bufcount; // 回合
	bool cant;
};

int main()
{
	Role user{ 3000, 3000, 1000, 1000, 50,0, false };
	Role boss{ 30000, 30000, 1000, 1000, 190,0, false };

	int inKey, damage{};

lfight:
	system("cls");
	printf("生命{ %d / %d}                      BOSS生命{ %d / %d}\n", user.Hp, user.MaxHp, boss.Hp, boss.MaxMp);
	printf("内力{ %d / %d} 攻击力 {%d}", user.Mp, user.MaxMp, user.act);

	inKey = _getch();
	damage = 0;

	switch (inKey)
	{
	case 49:
		if (user.MaxMp > 99)
		{
			user.Mp -= 100;
			user.Hp += 300;
			user.Hp = user.Hp > user.MaxHp ? user.MaxHp : user.Hp;
		}
		break;
	case 50:
		if (user.Mp >= 50)
		{
			user.Mp -= 50;
			damage = 50 + user.act;
		}
		break;
	case 51:
		if (user.Mp >= 50)
		{
			user.Mp -= 50;
			boss.cantact = 3;
		}
		break;
	case 52:
		user.bufcount = 10;
		break;
	case 53:
		if (user.Mp >= 100)
		{
			user.Mp -= 100;
			damage = user.MaxMp - user.Hp + user.act;
		}
		break;
	case 54:
		if ((user.Mp >= 300) && (!user.cant))
		{
			int ls = user.MaxHp;
			user.MaxHp = user.MaxMp;
			user.MaxMp = ls;
			ls = user.Hp;
			user.Hp = user.Mp;
			user.Mp = ls;

			user.act *= 10;
			user.cant = true;
		}
		break;
	}

	if (boss.cantact > 0)
	{
		boss.cantact--;
	}
	else
	{
		user.Hp -= boss.act;
	}

	boss.Hp -= damage;
	if (user.bufcount > 0)
	{
		user.bufcount--;
		user.Hp += damage * 0.6;
		user.Mp += damage * 0.2;
		user.Hp = user.Hp > user.MaxHp ? user.MaxHp : user.Hp;
		user.Mp = user.Mp > user.MaxMp ? user.MaxMp : user.Mp;
	}
	if (user.Hp < 1)
	{
		system("cls");
		printf("游戏结束:");
	}
	else if (boss.Hp < 1)
	{
		system("cls");
		printf("击败BOSS");
	}
	else
	{
		goto lfight;
	}

	return 0;
}