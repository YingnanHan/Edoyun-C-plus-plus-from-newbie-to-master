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

struct SKill
{
	int needMP;
	int AddAct;
	int cantact;
};

int main()
{
	Role roles[2] =
	{
		{ 3000, 3000, 1000, 1000, 50,0, false },
		{ 30000, 30000, 1000, 1000, 190,0, false }
	};

	SKill skill[5] =
	{
		{30, 50, 0},
		{0,0,1},
		{},
		{},
		{}
	};

	do
	{
		system("cls");
		printf("生命{ %d / %d}                      BOSS生命{ %d / %d}\n", roles[0].Hp, roles[0].MaxHp, roles[0].Mp, roles[0].MaxMp);
		printf("内力{ %d / %d} 攻击力 {%d}", roles[0].Mp, roles[0].MaxHp, roles[0].act);

		int key = _getch() - 49;
		roles[0].Mp = -skill[key].needMP;
		roles[1].Mp = roles[1].Hp - skill[key].AddAct - roles[0].act;
	} while (true);


	return 0;
}