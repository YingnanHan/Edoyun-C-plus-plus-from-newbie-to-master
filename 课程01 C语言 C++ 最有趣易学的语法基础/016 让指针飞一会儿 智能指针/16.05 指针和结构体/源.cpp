#include<iostream>

using namespace std;

typedef struct Role // ��һ�α���֮���ڱ��������治����
{
	int HP;
	int MP; // ���ڴ��лᵼ���ڴ���룬����Ķ��뷽ʽ�����ϵͳ�й�
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