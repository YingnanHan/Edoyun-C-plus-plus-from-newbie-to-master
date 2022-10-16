#include<iostream>

using namespace std;

class DOG
{

};

class WOLF
{
public:

	static void count()
	{

	}

	WOLF()
	{

	}

	void GrowUP0()
	{
		std::cout << "成长到了一阶段!" << std::endl;
	}

	void GrowUP1()
	{
		std::cout << "成长到了二阶段!" << std::endl;
	}

	void GrowUP2()
	{
		std::cout << "成长到了三阶段!" << std::endl;
	}
};

typedef void (WOLF::*PGOURP)(); //声明一个WOLF类型的函数指针

void X()
{

}

typedef void(*COUNT)(); //类的静态成员没有this指针，所以可以把它当做普通函数来使用

int main()
{
	PGOURP pFunction = &WOLF::GrowUP0; // 获取函数指针
	WOLF* pWolf = new WOLF();
	DOG* pDog = new DOG();
	(pWolf->*pFunction)();
	// (pDog->*pFunction)(); //错误

	COUNT _count = &WOLF::count; // 获取静态函数的指针
	_count();
	return 0;
}