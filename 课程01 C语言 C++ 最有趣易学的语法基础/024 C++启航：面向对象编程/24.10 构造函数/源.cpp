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

	T(T& t) //  这里必须使用引用
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
	Role role;
	Role user;
	user.SetLv(100);
	role.SetLv(200);

	std::cout << user.IsBig(role);
	//std::cout << user.IsBig(200); //由系统类型到自定义类型的隐式转换 会自动调用Role(int _lv) 但是禁用了该函数就不会进行隐式转换

	return 0;
}