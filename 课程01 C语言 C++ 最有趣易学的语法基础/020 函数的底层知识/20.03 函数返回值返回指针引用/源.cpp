#include<iostream>

// 定义角色信息结构体
typedef struct Role
{
	char* Name;
	int Hp;
	int MaxHp;
	int Mp;
	int maxMp;
	int lv;
}*PROLE, ROLE;

// 计算字符串常量的长度并返回
int clen(const char* str)
{
	int i;
	for (i = 0; str[i]; i++)
	{

	}
	return ++i;
}

// 在堆空间上拷贝字符串并返回
char* cstr(const char* str)
{
	int len = clen(str); // 计算字符串的长度
	char* strRt = new char[len]; // 按照字符串的长度重新再heap上分配内存空间
	memcpy(strRt, str, len); // 将字符串重新拷贝到堆上
	return strRt; // 返回重新生成的字符串
}

// 定义创建角色的函数
PROLE CreateMonster(const char* str, int Hp, int Mp)
{
	PROLE rt = new ROLE{ cstr(str), Hp, Hp, Mp, Mp, 1 };
	return rt;
}

ROLE& CreateMonster_(const char* str, int Hp, int Mp)
{
	PROLE rt = new ROLE{ cstr(str), Hp, Hp, Mp, Mp, 1 };
	return *rt;
}

int main()
{
	// 使用指针的传递防止性能的折损
	PROLE role = CreateMonster("ultraman",1500, 1500);

	std::cout << role->Name << std::endl;
	std::cout << role->Hp << "/" << role->MaxHp;


	ROLE& role1 = CreateMonster_("ultraman", 1500, 1500);

	std::cout << role1.Name << std::endl;
	std::cout << role1.Hp << "/" << role1.MaxHp;
	return 0;
}