#pragma once

#include<iostream>

using namespace std;

//�б������ʼ����˳���Ǳ��������˳��
class Role
{
private:
	int hpRecover;
	void Init(); // ��Ҫ���ⲿ����ĺ�������Ҫ�������ڲ�����
	int hp;
public:
	//Role() // �Զ���Ĭ�Ϲ��캯��
	//{
	//	//std::cout << "�Զ���Ĭ�Ϲ��캯��" << std::endl;
	//}

	bool IsBig(Role rl)
	{
		return rl.GetLv() > lv;
	}

	Role(const Role& role) : hp(role.hp) //�������캯���ĳ�ʼ�����ֿ��Է���˽�л���Ա
	{
		// �������캯����ʼ����ʱ�������ʼ����ָ��������
		// ͬһ�����ǿ��Է���ͬһ��������Ϊ������˽�б���
	}

	// ί�й��캯��ֻ����ʹ��һ�Σ�������������δ��ʼ���Ĳ�����Ҫ�ں����ڲ�����
	Role(int _lv, int damage) : Role(_lv) // ʹ�ó�Ա��ʼ���б�,�ں���ִ��֮ǰ���Ѿ���ֵ��ʼ��
	{
		this->damage =  damage ;
		std::cout << "lv:" << lv << " " << "damage:" << damage << std::endl;
	}

	Role() = default; // �Զ���Ĭ�Ϲ��캯�� better

	explicit Role(int _lv)  // �Զ��幹�캯�� ע������Ĳ�����������Ĭ�ϲ�������ᵼ������
	{
		lv = _lv;
	}

	int lv;
	int damage;

	void Act(Role& role); // ��Ҫ���ⲿ����ĺ�������Ҫ�������ڲ�����

	inline int GetHP() const // ���������Ƽ�д��ͷ�ļ��� ����const�ؼ��ֵĻ��Ϳ�����constָ����ʹ�øú���
	{
		// this->hp = 2; // ���󣺱��ʽ�����ǿ��޸ĵ���ֵ
		return hp;
	}

	Role* bigger(Role* role);
	Role& SetLv(int newLv);
	Role& SetHp(int newHp);
	Role& SetDamage(int newDamage);

	int GetLv() const;
	//int& GetLv() const; // ����ĺ��������Ա��룬�﷨����ì�ܵ� ����Ϊ�˱���ͨ��ʹ�������������ֵ��Ϊconst int&,��Ȼ�������ᵼ��main()_��������ĵ���ʧ��
	int& GetLv();

	int GetDamage() const;
	int GetDamage();
};