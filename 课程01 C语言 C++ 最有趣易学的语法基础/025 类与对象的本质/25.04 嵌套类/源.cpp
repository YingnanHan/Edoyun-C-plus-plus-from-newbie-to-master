#include<iostream>
/*
	 Ƕ������Է������������г�Ա
	 �������ܷ���Ƕ����Ĺ��г�Ա
*/
using namespace std;

enum class WeaponLv // ö�����Ϳ��Էŵ����public����
{
	normal = 0,
	high,
	rare,
	myth
};

class Role
{
public:
	static void test()
	{

	}
	Role()
	{
		Weapon::test1(); // ��㺯��������ͨ�����������������������ڲ��ྲ̬public���εĳ�Ա
	}
	class Weapon
	{
		Weapon* ReturnW();
	public:
		static void test1()
		{

		}
		Weapon()
		{
			test(); //�ڲ�Ƕ������Է�����㾲̬����/��Ա
		}
		short lv;
		WeaponLv wlv;
	};
	int hp;
	int mp;
	// Weapon leftHands;
};

//Role::Weapon::Weapon()
//{
//	std::cout << "weapon";
//}

Role::Weapon* Role::Weapon::ReturnW()
{
	return this;
}

int main()
{
	Role rl;
	Role::Weapon wpl;

	return 0;
}