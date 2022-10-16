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
		//std::cout << this << std::endl;
		this->Move();
		// 本函数输出 MoveObject Moving 输出这个结果的原因是 当MonsterObject开始构建的时候，
		// 先构建基类再构建派生类，此前不存在派生类信息，所以到这里为止，输出的是MoveObject
		// Moving
	}
	virtual void Move()
	{
		//std::cout << "MoveObject Moving!" << std::endl;
	}
	virtual void AutoMove(int step = 2)
	{
		//std::cout << " ------> auto move:" << step << std::endl;
	}
	void test()
	{
		this->Move();
	}

	virtual ~MoveObject() // 如果不写程序函数会导致错误
	{
		cout << "~MoveObject" << endl;
		Move();
	}
};

class MonsterObject : public MoveObject
{
public:
	MonsterObject()
	{
		//std::cout << this << std::endl;
		MoveObject::test();
		// 本函数输出 MonsterObject Moving 输出这个结果的原因是 当MonsterObject开始构建的时候，
		// 先构建基类再构建派生类，并且派生类已经构造完了，所以到这里为止，输出的是MoveObject
		// Moving
	}
	virtual void Move() override // 重写虚函数
	{
		//std::cout << "MonsterObject Moving!" << std::endl;
	}
	virtual void AutoMove(int step = 3) override
	{
		//std::cout << " ======> auto move:" << step << std::endl;
	}
	virtual ~MonsterObject()
	{
		cout << "~MonsterObject" << endl;
		MoveObject::Move(); // 指定调用的虚函数版本
	}
};
// C++标准委员会为了安全起见构造函数被设计为静态绑定
int main()
{
	MonsterObject snake;
	MoveObject* p = new MonsterObject();
	p->AutoMove();
	delete p; // 如果这里调用的不是虚析构函数，那就仅仅调用MoveObject对象p的自己的析构函数
}

/*
虚函数框架下 构造函数与析构函数的被调用次序是相反的
*/