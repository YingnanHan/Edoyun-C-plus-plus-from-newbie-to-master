#include<iostream>

class MoveObject
{

};

class MonsterObject : public MoveObject
{

};

class NPCObject : public MoveObject
{

};

class WOLF : public MonsterObject
{

};

class MAN : public MonsterObject
{

};

class WOLFMAN :public WOLF, public MAN
{

};

int main()
{
	// 01 如果基类是虚的，那么从父类到子类的转换是不被允许的
	MonsterObject monster;
	MoveObject* _move = (MoveObject*) & monster; // 向上隐式转换
	// MonsterObject* _pmonster = _move; // 隐式向下转换被禁止
	// 下面这两句话如果子类不是虚的就可以通过编译
	// MonsterObject* _pmonster = (MonsterObject*)_move; // 强制类型转换是被允许的
	// MonsterObject* _pmonsterA = static_cast<MonsterObject*>(_move); // 隐式强制转换


	// 02

	WOLFMAN wolfman;

	void* ptr = &wolfman;
	WOLF* pWlf = &wolfman;
	MAN* pMan = &wolfman;
	std::cout << ptr << "\n" << pWlf << "\n" << pMan << "\n";

	pWlf = (WOLF*)ptr; // 类型转换 void* -> WOLF*
	pMan = (MAN*)ptr;
	std::cout << ptr << "\n" << pWlf << "\n" << pMan << "\n";

	pWlf = (WOLF*)&wolfman; // 类型转换 void* -> WOLF*
	pMan = (MAN*)&wolfman;
	std::cout << ptr << "\n" << pWlf << "\n" << pMan << "\n";
	return 0;
}