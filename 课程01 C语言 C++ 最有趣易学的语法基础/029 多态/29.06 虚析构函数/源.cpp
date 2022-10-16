#include<iostream>

using namespace std;

class MoveObject
{
private:
	int x;
	int y;
public:
	MoveObject()
	{
		std::cout << this << std::endl;
		this->Move();
		// 本函数输出 MoveObject Moving 输出这个结果的原因是 当MonsterObject开始构建的时候，
		// 先构建基类再构建派生类，此前不存在派生类信息，所以到这里为止，输出的是MoveObject
		// Moving
	}
	virtual void Move()
	{
		std::cout << "MoveObject Moving!" << std::endl;
	}
	void test()
	{
		this->Move();
	}

	~MoveObject()
	{
		Move();
	}
};

class MonsterObject : public MoveObject
{
public:
	MonsterObject()
	{
		std::cout << this << std::endl;
		MoveObject::test();
		// 本函数输出 MonsterObject Moving 输出这个结果的原因是 当MonsterObject开始构建的时候，
		// 先构建基类再构建派生类，并且派生类已经构造完了，所以到这里为止，输出的是MoveObject
		// Moving
	}
	virtual void Move() override // 重写虚函数
	{
		std::cout << "MonsterObject Moving!" << std::endl;
	}
	~MonsterObject()
	{
		Move();
	}
};
// C++标准委员会为了安全起见构造函数被设计为静态绑定
int main()
{
	MonsterObject snake;
	snake.Move(); // 输出 MonsterObject Moving!
	return 0;
}

/*
虚函数框架下 构造函数与析构函数的被调用次序是相反的
*/