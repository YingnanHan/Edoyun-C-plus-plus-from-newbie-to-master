#include<iostream>

class MoveObject
{
public:
	virtual void test()
	{

	}

};

class Monster : public MoveObject
{
public:
	virtual void test()
	{

	}
};

int main()
{
	//针对指针的情况
	MoveObject* _move = new MoveObject();
	_move = new Monster();
	std::cout << typeid(*_move).name();

	std::cout << std::endl;

	//针对引用的情况
	MoveObject wolf;
	MoveObject& lMove = wolf;
	std::cout << typeid(lMove).name() << std::endl;;	// 引用不需要还原 解引用

	// typeid可以用来做判断
	int a;
	if (typeid(int) == typeid(a))
	{
		std::cout << "right" << std::endl;
	}
	else
	{
		std::cout << "wrong" << std::endl;
	}

	if (typeid(lMove) == typeid(MoveObject))
	{
		std::cout << "right" << std::endl;
	}
	else
	{
		std::cout << "wrong" << std::endl;
	}
	return 0;
}