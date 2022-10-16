#include<iostream>

using namespace std;

typedef struct Role // 这一段编译之后在编译器里面不存在
{
	int HP;
	int MP; // 在内存中会导致内存对齐，具体的对齐方式与操作系统有关
}*PRole;

int main()
{
	Role user;
	PRole puser = &user;

	puser->HP = 50;
	puser->MP = 50;

	user.MP = 50;
	user.HP = 50;
}