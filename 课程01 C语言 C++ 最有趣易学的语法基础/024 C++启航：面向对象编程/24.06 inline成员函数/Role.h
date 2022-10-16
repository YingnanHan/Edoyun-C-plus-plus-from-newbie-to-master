#pragma once
class Role
{
private:
	int hpRecover;
	void Init(); // 需要在外部定义的函数必须要先在类内部声明
	int hp;
public:
	int lv;
	int damage;
	void Act(Role& role); // 需要在外部定义的函数必须要先在类内部声明
	inline int GetHP() const // 内联函数推荐写在头文件里 加上const关键字的话就可以在const指针下使用该函数
	{
		// this->hp = 2; // 错误：表达式必须是可修改的左值
		return hp;
	}
	Role* bigger(Role* role);

	Role& SetLv(int newLv);
	Role& SetHp(int newHp);
	Role& SetDamage(int newDamage);

	int GetLv() const;
	//int& GetLv() const; // 这里的函数不可以编译，语法上是矛盾的 或者为了编译通过使得这个函数返回值变为const int&,当然这样做会导致main()_函数里面的调用失败
	int& GetLv();

	int GetDamage() const;
	int GetDamage();
};