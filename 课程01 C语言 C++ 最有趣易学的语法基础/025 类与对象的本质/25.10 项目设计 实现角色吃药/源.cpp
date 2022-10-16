#include<iostream>

using namespace std;

class HPMed
{
public:
	int Recover{100};

};

class Role
{
	int hp;
	int maxHp;
public:
	Role()
	{
		hp = 1000;
		maxHp = 3500;
	}

	void GetHP()
	{
		std::cout << "HP:" << hp << "\\" << maxHp << std::endl;
	}

	void EatMed(HPMed& hpMed)
	{
		hp += hpMed.Recover;
		hp = hp > maxHp ? maxHp : hp;
	}
};

int main()
{
	Role user;
	HPMed med;

	user.GetHP();

	while (1)
	{
		int a;
		std::cin >> a;
		user.EatMed(med);
		system("cls");
		user.GetHP();
	}

	return 0;
}