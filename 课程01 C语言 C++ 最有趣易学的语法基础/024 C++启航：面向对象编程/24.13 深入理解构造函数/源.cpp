#include"Role.h"

class T
{
public:
	int hp;

	int GetMP()
	{
		return mp;
	}

	void SetMP(int _mp)
	{
		mp = _mp;
	}

	T()
	{
		std::cout << "T() called" << std::endl;
		hp = 100;
		mp = 800;
	}

	T(int hp_, int mp_)
	{
		std::cout << "T(int hp_, int mp_) called" << std::endl;
		hp = hp_;
		mp = mp_;
	}

	T(T& t) //  �������ʹ������
	{
		std::cout << "T(T) called\n";
		hp = t.hp;
		mp = t.GetMP();
	}

private:
	int mp;
};

int main()
{
	
	Role user(100, 200);
	user.SetHp(5000);
	std::cout << user.GetDamage() << " " << user.GetLv() << std::endl;

	Role userA(user); // �������캯����������Ĭ����ӵ�

	return 0;
}