// mutable�ؼ��������ı������Ա�const��Ա�����޸�
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