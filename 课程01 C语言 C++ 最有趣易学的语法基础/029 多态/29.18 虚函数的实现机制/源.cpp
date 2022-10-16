#include<iostream>
#include<Windows.h>

using namespace std;

void Hack()
{
	std::cout << "HHHHHHHHHHHHHHHHHHH" << std::endl;
}

class AIM
{
public:
	// [unknown]
	int HP; // +0x0
	virtual void Eat()
	{
		std::cout << "AIM" << std::endl;
	}

	virtual void Die()
	{
		std::cout << "AIM-DIE" << std::endl;
	}
};

class WOLF :public AIM
{
public:

	virtual void Eat()
	{
		std::cout << "WOLF_EAT" << std::endl;
	}

	virtual void Die()
	{
		std::cout << "WOLF_DIE" << std::endl;
	}

	void Sound()
	{
		std::cout << "aoaoaoaoaoaoao~~~" << std::endl;
	}
};

int main()
{
	AIM* wolf = new WOLF();
	wolf->Die();
	wolf->Eat();

	std::cout << sizeof(AIM) << std::endl;
	std::cout << wolf << " " << &wolf->HP << std::endl; // 二者相差四个字节

	unsigned* vtable = (unsigned*)wolf;
	std::cout << std::hex << "VTABLE : " << vtable[0] << std::endl;
	unsigned* func = (unsigned*)vtable[0];
	std::cout << std::hex << "eat : " << func[0] << std::endl;
	std::cout << std::hex << "eat : " << func[1] << std::endl;

	WOLF aWolf;
	aWolf.Sound();

	// 修改虚函数表 -- 调用WindowsAPI修改虚函数表不可访问权限
	DWORD old;
	VirtualProtect(func, 8, PAGE_EXECUTE_READWRITE, &old); // 修改权限
	func[0] = (unsigned)Hack; // 修改内容
	func[1] = (unsigned)Hack; // 修改内容
	wolf->Eat();
	WOLF aWlf;
	aWlf.Sound();
	aWlf.Eat();		// 不涉及多态

	AIM* _aim = new WOLF();
	_aim->Eat();

	return 0;
}

//虚表的性质
// （1）同一个类的多个实例都指向一个虚函数表
// （2）通过修改虚函数表的数据可以实现劫持
// （3）只有通过指针访问函数才会调用虚函数表