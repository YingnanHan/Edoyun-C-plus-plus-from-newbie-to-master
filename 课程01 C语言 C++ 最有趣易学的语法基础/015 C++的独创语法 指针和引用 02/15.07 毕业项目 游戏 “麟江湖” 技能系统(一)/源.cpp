#include<iostream>

using namespace std;

struct Skill
{
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

struct Role
{
	int Mp;
	int MaxMp;
	int Hp;
	int MaxHp;
	int Sp;
	int MaxSp;
	int Act;
	USkill skills[5];
};

int main()
{
	Skill AllSkills[11]
	{
		{0,0,10,1},
		{10,0,50,1},
		{10,0,60,1},
		{30,0,0,2},
		{30,0,300,0},
		{50,0,0,5},
		{50,0,500,0},
		{100,0,0,10},
		{100,0,50,2},
		{0,100,500,5},
		{0,100,200,10},
	};

	Role* User = new Role
	{
		1000, 1000, 1000, 1000, 0, 100, 100,
		{
			{&AllSkills[0],0,0,true},
			{&AllSkills[1],0,0,true},
			{&AllSkills[2],0,0,true},
			{&AllSkills[3],0,0,false},
			{&AllSkills[10],0,0,false},
		}
	};

	std::cout << "��ɫ����:��Ӣ��" << std::endl;
	std::cout << "����:" << User[0].Hp << "/" << User[0].MaxHp << std::endl;
	std::cout << "����:" << User[0].Mp << "/" << User[0].MaxMp << std::endl;
	std::cout << "ŭ��:" << User[0].Sp << "/" << User[0].MaxSp << std::endl;
	std::cout << "��������:" << User[0].Act << std::endl;

	for (auto skill : User[0].skills)
	{
		if (skill.buse)
		{
			std::cout
				<< "����MP" << skill.skill[0].Mpp
				<< "����SP" << skill.skill[0].Mpp
				<< "���ӹ���" << skill.skill[0].Mpp
				<< "��������" << skill.skill[0].Mpp
				<< std::endl;
		}
	}


	return 0;
}