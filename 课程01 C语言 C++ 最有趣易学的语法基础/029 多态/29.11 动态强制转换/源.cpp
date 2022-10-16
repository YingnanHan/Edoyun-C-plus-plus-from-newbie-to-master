#include<iostream>

using namespace std;

class MoveObject
{
public:
	int x;

	virtual void test()
	{

	}

	virtual void move()
	{

	}
};

class MonsterObject : public MoveObject
{
public:
	void monsterMove()
	{

	}

	virtual void move()
	{

	}
};

class NPCObject : public MoveObject
{
public:
	void NPCMove()
	{

	}

	virtual void move()
	{

	}
};

class BOSS
{

};

class WOLF : public MonsterObject
{

};

class MAN : public MonsterObject
{

};

class WOLFMAN : public MAN, /*public WOLF,*/ public BOSS
{

};



int main()
{
	// cast 01
	MonsterObject monster;
	MoveObject* _move = (MoveObject*)&monster;	// 隐式转换，向上转型

	// cast 02
	//MonsterObject* _pmonsterA = static_cast<MonsterObject*>(_move); // 可以转换

	// cast 03
	_move = new MoveObject();
	MonsterObject* _pmonsterA = static_cast<MonsterObject*>(_move); // 不可以转换 因为这种转换是向下转换 有一定的风险

	// cast 04
	_pmonsterA = dynamic_cast<MonsterObject*>(_move); // _move对象类中必须要有虚函数才可以转换
	if (_pmonsterA == nullptr)
	{
		std::cout << "转换失败" << std::endl;
	}
	else
	{
		std::cout << "转换成功" << std::endl;
	}

	_move = (MoveObject*)&monster;
	_pmonsterA = dynamic_cast<MonsterObject*>(_move); // _move对象类中必须要有虚函数才可以转换
	auto _pNPCA = dynamic_cast<NPCObject*>(_move);
	if (_pmonsterA == nullptr)
	{
		std::cout << "转换失败" << std::endl;
	}
	else
	{
		std::cout << "转换成功" << std::endl;
	}
	// 这一部分写的不合理05中将被重写
	if (_pmonsterA != nullptr)
	{
		_pmonsterA->monsterMove();
	}
	else if(_pNPCA != nullptr)
	{
		_pNPCA->NPCMove();
	}

	// 05 上面代码的正确写法
	_move->move();

	// 06 跨类转换
	WOLFMAN wlfman;
	MoveObject* pMove = &wlfman;
	dynamic_cast<WOLFMAN*>(pMove); // 可以转换 当且仅当存在部分继承关系
	auto p = dynamic_cast<BOSS*>(pMove); // 可以转换 当且仅当存在部分继承关系
	std::cout << p;

	/*
	dynamic_cast <type-id> (expression)
	该运算符把expression转换成type-id类型的对象。Type-id 必须是类的指针、类的引用或者void*；
	如果 type-id 是类指针类型，那么expression也必须是一个指针，如果 type-id 是一个引用，那么
	expression 也必须是一个引用。
	dynamic_cast运算符可以在执行期决定真正的类型。如果 downcast 是安全的（也就说，如果基类指
	针或者引用确实指向一个派生类对象）这个运算符会传回适当转型过的指针。如果 downcast 不安全
	，这个运算符会传回空指针（也就是说，基类指针或者引用没有指向一个派生类对象）。
	dynamic_cast主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换。在类层次间
	进行上行转换时，dynamic_cast和static_cast的效果是一样的；在进行下行转换时，dynamic_cast具
	有类型检查的功能，比static_cast更安全。
	*/
	return 0;
}