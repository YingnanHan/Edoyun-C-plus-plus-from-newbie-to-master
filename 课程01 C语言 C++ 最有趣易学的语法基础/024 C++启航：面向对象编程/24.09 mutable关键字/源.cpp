// mutable关键字生命的变量可以被const成员函数修改
#include<iostream>

using namespace std;

class Role
{
private:
	int hp;
	mutable int getHPCount;
public:
	int GetHp() const;
};

int Role::GetHp() const
{
	getHPCount++;
	return getHPCount;
}

int main()
{
	const Role r = Role();
	cout << r.GetHp() << std::endl;
	r.GetHp();
	cout << r.GetHp() << std::endl;
	r.GetHp();
	cout << r.GetHp() << std::endl;
	r.GetHp();
	return 0;

}