#pragma once
class Role
{
private:
	int hpRecover;
	void Init(); // ��Ҫ���ⲿ����ĺ�������Ҫ�������ڲ�����
	int hp;
public:
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