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
	unsigned char lv{ 1 }; // 等级
	SCHOOL		  school{ SCHOOL::edoyun };// 门派
	Equip		  weapon{ 1,1 };// 武器
	Equip		  army{ 1,10 };// 护甲
	Equip		  neck{ 1,10 };// 项链
	long long	  exp{ 0 };// 经验值
	RoleState	  HP{ 1000, 1000 };// 血量
	RoleState	  MP{ 1000, 1000 };// 生命值
	unsigned	  x{ 500 }; // 横轴位置坐标
	unsigned	  y{ 500 }; // 纵轴位置坐标
	unsigned	  Money{ 1000 }; // 金钱数目
	unsigned	  Diamond{ 100 }; // 钻石数目
	unsigned char luck{ 2 }; // 幸运值
	unsigned	  vip_exp; // VIP经验加成
};

int main()
{
	Role user;
	std::cout << "生命:" << user.HP.value << "/" << user.HP.maxValue << std::endl;
	std::cout << "内力:" << user.MP.value << "/" << user.MP.maxValue << std::endl;
	std::cout << "坐标:[" << user.x << "][" << user.y << "]" << std::endl;
	// 定义人物关系
	Role user_master;
	Role user_wife;
}