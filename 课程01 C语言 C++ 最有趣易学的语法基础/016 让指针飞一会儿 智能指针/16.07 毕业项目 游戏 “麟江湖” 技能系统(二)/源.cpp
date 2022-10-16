#include<iostream>

using namespace std;

struct Skill
{
	char Name[48];
	int Mpp;		// ��������
	int Spp;		// ŭ��
	int Act;		// ������
	int ActB;		// ��������
	int CoolDown;	// ��ȴʱ��
	int Lv;			// ���ܵȼ�
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
		{"��ͨ����",0,0,10,1},
		{"�������ָ",10,0,50,1},
		{"��������",10,0,60,1},
		{"һ��ָ",30,0,0,2},
		{"ӭ������",30,0,300,0},
		{"������",50,0,0,5},
		{"���ϰ˻�",50,0,500,0},
		{"����ָ·",100,0,0,10},
		{"��ɨǧ��",100,0,50,2},
		{"����ɽ��",0,100,500,5},
		{"��絶��",0,100,200,10},
	};

	PROLE User = new Role
	{
		"��Ӣ��", 1000, 1000, 1000, 1000, 0, 100, 100,
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
		"������", 1000, 1000, 1000, 1000, 0, 100, 100,
		{
			{&AllSkills[0],0,0,true},
			{&AllSkills[1],0,0,true},
			{&AllSkills[2],0,0,true},
			{&AllSkills[4],0,0,false},
			{&AllSkills[10],0,0,false},
		}
	};

	std::cout << "��ɫ����:" << User->Name << std::endl;
	std::cout << "����:" << User->Hp << "/" << User->MaxHp << std::endl;
	std::cout << "����:" << User->Mp << "/" << User->MaxMp << std::endl;
	std::cout << "ŭ��:" << User->Sp << "/" << User->MaxSp << std::endl;
	std::cout << "��������:" << User->Act << std::endl;

	for (auto skill : User->skills)
	{
		if (skill.buse)
		{
			std::cout
				<< "�������� " << skill.skill->Name << "\t"
				<< "����MP " << skill.skill->Mpp << "\t"
				<< "����SP " << skill.skill->Mpp << "\t"
				<< "���ӹ��� " << skill.skill->Mpp << "\t"
				<< "�������� " << skill.skill->Mpp << "\t"
				<< std::endl;
		}
	}
	return 0;
}