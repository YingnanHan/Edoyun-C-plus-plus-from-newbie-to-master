#include<iostream>
#include"Role.h"

using namespace std;

void test(Role* p)
{
	p->SetHp(5000);
}

int main()
{
	// �� �������ƹ���Ա����ͨ����Ա�������޸�const����
	
	const Role user{}; // user �ĳ�Ա���������Ա��ı�
	Role monster;
	const Role* puser{ &user }; //ָ����һ��const�����Ըö��󲻿��Ը�
	// puser->damage = 200; // ����

	// �� ���const������д���const��������ô�Ϳ���ֱ�ӵ��øú���������ĳһЩ�������޸�

	// const Role user; // user �ĳ�Ա���������Ա��ı�
	// Role monster;
	// const Role* puser{ &monster }; //ָ����һ��const�����Ըö��󲻿��Ը�
	//puser->damage = 200; // ����
	puser->GetHP();
	monster.GetHP();

	// �� const����ֻ�ܵ���const��Ա����

	monster.GetLv() = 200; // ����һ�����ò�����һ�����Ա��޸ĵ���ֵ
	// ʵ���ϲ����Ƽ����������д����һ��Ļ�Ӧ��д��monster.SetLv(200);
	std::cout << monster.GetLv() << endl;;
	monster.SetDamage(100);
	std::cout << monster.GetDamage() << std::endl;

	// �� ǿ������ת��
	test((Role*)(&user)); // ����һ
	std::cout << puser->GetHP() << std::endl;
	test(const_cast<Role*>(&user)); // ������ ��ֹ��ֵ������ȥ
	std::cout << puser->GetHP();
	return 0;
}

/*
constԭ��
	const���������κη�ʽ�ı䣬����const��ԭ�����������ԭ���£�������һϵ��ЧӦ������
	const����ֻ�ܵ���const����
	����һ�����ǲ�ע��ı仯�ǣ���const��Ա�����£�thisָ��Ҳ�����constָ��
*/