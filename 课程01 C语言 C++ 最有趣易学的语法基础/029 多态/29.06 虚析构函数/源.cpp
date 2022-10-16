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
		// ��������� MoveObject Moving �����������ԭ���� ��MonsterObject��ʼ������ʱ��
		// �ȹ��������ٹ��������࣬��ǰ��������������Ϣ�����Ե�����Ϊֹ���������MoveObject
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
		// ��������� MonsterObject Moving �����������ԭ���� ��MonsterObject��ʼ������ʱ��
		// �ȹ��������ٹ��������࣬�����������Ѿ��������ˣ����Ե�����Ϊֹ���������MoveObject
		// Moving
	}
	virtual void Move() override // ��д�麯��
	{
		std::cout << "MonsterObject Moving!" << std::endl;
	}
	~MonsterObject()
	{
		Move();
	}
};
// C++��׼ίԱ��Ϊ�˰�ȫ������캯�������Ϊ��̬��
int main()
{
	MonsterObject snake;
	snake.Move(); // ��� MonsterObject Moving!
	return 0;
}

/*
�麯������� ���캯�������������ı����ô������෴��
*/