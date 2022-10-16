#include<iostream>

using namespace std;

struct Skill
{
	char Name[48];
	int Mpp;		// 内力消耗
	int Spp;		// 怒气
	int Act;		// 攻击力
	int ActB;		// 翻倍攻击
	int CoolDown;	// 冷却时间
	int Lv;			// 技能等级
};

struct USkill
{
	Skill* skill{};
	int lv;
	int cooldown;
	bool buse{ };
};

typedef struct Role
{
	char Name[48];
	int Mp;
	int MaxMp;
	int Hp;
	int MaxHp;
	int Sp;
	int MaxSp;
	int Act;
	USkill skills[5];
}*PROLE;

int main()
{
	Skill AllSkills[11]
	{
		{"普通攻击",0,0,10,1},
		{"大力金刚指",10,0,50,1},
		{"云龙三观",10,0,60,1},
		{"一阳指",30,0,0,2},
		{"迎风破浪",30,0,300,0},
		{"八卦掌",50,0,0,5},
		{"六合八荒",50,0,500,0},
		{"仙人指路",100,0,0,10},
		{"横扫千军",100,0,50,2},
		{"气吞山河",0,100,500,5},
		{"秋风刀法",0,100,200,10},
	};

	PROLE User = new Role
	{
		"郝英俊", 1000, 1000, 1000, 1000, 0, 100, 100,
		{
			{&AllSkills[0],0,0,true},
			{&AllSkills[1],0,0,true},
			{&AllSkills[2],0,0,true},
			{&AllSkills[3],0,0,false},
			{&AllSkills[10],0,0,false},
		}
	};

	PROLE Master = new Role
	{
		"奥特曼", 1000, 1000, 1000, 1000, 0, 100, 100,
		{
			{&AllSkills[0],0,0,true},
			{&AllSkills[1],0,0,true},
			{&AllSkills[2],0,0,true},
			{&AllSkills[4],0,0,false},
			{&AllSkills[10],0,0,false},
		}
	};

	std::cout << "角色姓名:" << User->Name << std::endl;
	std::cout << "生命:" << User->Hp << "/" << User->MaxHp << std::endl;
	std::cout << "内力:" << User->Mp << "/" << User->MaxMp << std::endl;
	std::cout << "怒气:" << User->Sp << "/" << User->MaxSp << std::endl;
	std::cout << "基本攻击:" << User->Act << std::endl;

	for (auto skill : User->skills)
	{
		if (skill.buse)
		{
			std::cout
				<< "技能名称 " << skill.skill->Name << "\t"
				<< "消耗MP " << skill.skill->Mpp << "\t"
				<< "消耗SP " << skill.skill->Mpp << "\t"
				<< "附加攻击 " << skill.skill->Mpp << "\t"
				<< "翻倍攻击 " << skill.skill->Mpp << "\t"
				<< std::endl;
		}
	}
	return 0;
}