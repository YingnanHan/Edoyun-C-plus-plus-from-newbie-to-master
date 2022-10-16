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
	MoveObject* _move = (MoveObject*)&monster;	// ��ʽת��������ת��

	// cast 02
	//MonsterObject* _pmonsterA = static_cast<MonsterObject*>(_move); // ����ת��

	// cast 03
	_move = new MoveObject();
	MonsterObject* _pmonsterA = static_cast<MonsterObject*>(_move); // ������ת�� ��Ϊ����ת��������ת�� ��һ���ķ���

	// cast 04
	_pmonsterA = dynamic_cast<MonsterObject*>(_move); // _move�������б���Ҫ���麯���ſ���ת��
	if (_pmonsterA == nullptr)
	{
		std::cout << "ת��ʧ��" << std::endl;
	}
	else
	{
		std::cout << "ת���ɹ�" << std::endl;
	}

	_move = (MoveObject*)&monster;
	_pmonsterA = dynamic_cast<MonsterObject*>(_move); // _move�������б���Ҫ���麯���ſ���ת��
	auto _pNPCA = dynamic_cast<NPCObject*>(_move);
	if (_pmonsterA == nullptr)
	{
		std::cout << "ת��ʧ��" << std::endl;
	}
	else
	{
		std::cout << "ת���ɹ�" << std::endl;
	}
	// ��һ����д�Ĳ�����05�н�����д
	if (_pmonsterA != nullptr)
	{
		_pmonsterA->monsterMove();
	}
	else if(_pNPCA != nullptr)
	{
		_pNPCA->NPCMove();
	}

	// 05 ����������ȷд��
	_move->move();

	// 06 ����ת��
	WOLFMAN wlfman;
	MoveObject* pMove = &wlfman;
	dynamic_cast<WOLFMAN*>(pMove); // ����ת�� ���ҽ������ڲ��ּ̳й�ϵ
	auto p = dynamic_cast<BOSS*>(pMove); // ����ת�� ���ҽ������ڲ��ּ̳й�ϵ
	std::cout << p;

	/*
	dynamic_cast <type-id> (expression)
	���������expressionת����type-id���͵Ķ���Type-id ���������ָ�롢������û���void*��
	��� type-id ����ָ�����ͣ���ôexpressionҲ������һ��ָ�룬��� type-id ��һ�����ã���ô
	expression Ҳ������һ�����á�
	dynamic_cast�����������ִ���ھ������������͡���� downcast �ǰ�ȫ�ģ�Ҳ��˵���������ָ
	���������ȷʵָ��һ��������������������ᴫ���ʵ�ת�͹���ָ�롣��� downcast ����ȫ
	�����������ᴫ�ؿ�ָ�루Ҳ����˵������ָ���������û��ָ��һ����������󣩡�
	dynamic_cast��Ҫ�������μ������ת��������ת����������������֮��Ľ���ת���������μ�
	��������ת��ʱ��dynamic_cast��static_cast��Ч����һ���ģ��ڽ�������ת��ʱ��dynamic_cast��
	�����ͼ��Ĺ��ܣ���static_cast����ȫ��
	*/
	return 0;
}