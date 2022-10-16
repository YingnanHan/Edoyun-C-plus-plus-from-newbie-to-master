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
		// ��������� MoveObject Moving �����������ԭ���� ��MonsterObject��ʼ������ʱ��
		// �ȹ��������ٹ��������࣬��ǰ��������������Ϣ�����Ե�����Ϊֹ���������MoveObject
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

	virtual ~MoveObject() // �����д�������ᵼ�´���
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
		// ��������� MonsterObject Moving �����������ԭ���� ��MonsterObject��ʼ������ʱ��
		// �ȹ��������ٹ��������࣬�����������Ѿ��������ˣ����Ե�����Ϊֹ���������MoveObject
		// Moving
	}
	virtual void Move() override // ��д�麯��
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
		MoveObject::Move(); // ָ�����õ��麯���汾
	}
};
// C++��׼ίԱ��Ϊ�˰�ȫ������캯�������Ϊ��̬��
int main()
{
	MonsterObject snake;
	MoveObject* p = new MonsterObject();
	p->AutoMove();
	delete p; // ���������õĲ����������������Ǿͽ�������MoveObject����p���Լ�����������
}

/*
�麯������� ���캯�������������ı����ô������෴��
*/