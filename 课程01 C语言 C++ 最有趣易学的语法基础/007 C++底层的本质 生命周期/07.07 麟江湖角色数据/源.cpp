#include<iostream>

enum class SCHOOL : char
{
	wudang,
	emei,
	edoyun,
	kuihua,
	tangmen
};

struct Equip
{
	unsigned char lv{ 0 };
	unsigned char ev{ 0 };
};

struct RoleState
{
	int value{ 1000 };
	unsigned maxValue{ 1000 };
};

struct Role
{
	unsigned char lv{ 1 }; // �ȼ�
	SCHOOL		  school{ SCHOOL::edoyun };// ����
	Equip		  weapon{ 1,1 };// ����
	Equip		  army{ 1,10 };// ����
	Equip		  neck{ 1,10 };// ����
	long long	  exp{ 0 };// ����ֵ
	RoleState	  HP{ 1000, 1000 };// Ѫ��
	RoleState	  MP{ 1000, 1000 };// ����ֵ
	unsigned	  x{ 500 }; // ����λ������
	unsigned	  y{ 500 }; // ����λ������
	unsigned	  Money{ 1000 }; // ��Ǯ��Ŀ
	unsigned	  Diamond{ 100 }; // ��ʯ��Ŀ
	unsigned char luck{ 2 }; // ����ֵ
	unsigned	  vip_exp; // VIP����ӳ�
};

int main()
{
	Role user;
	std::cout << "����:" << user.HP.value << "/" << user.HP.maxValue << std::endl;
	std::cout << "����:" << user.MP.value << "/" << user.MP.maxValue << std::endl;
	std::cout << "����:[" << user.x << "][" << user.y << "]" << std::endl;
	// ���������ϵ
	Role user_master;
	Role user_wife;
}