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
	// 01 �����������ģ���ô�Ӹ��ൽ�����ת���ǲ��������
	MonsterObject monster;
	MoveObject* _move = (MoveObject*) & monster; // ������ʽת��
	// MonsterObject* _pmonster = _move; // ��ʽ����ת������ֹ
	// ���������仰������಻����ľͿ���ͨ������
	// MonsterObject* _pmonster = (MonsterObject*)_move; // ǿ������ת���Ǳ������
	// MonsterObject* _pmonsterA = static_cast<MonsterObject*>(_move); // ��ʽǿ��ת��


	// 02

	WOLFMAN wolfman;

	void* ptr = &wolfman;
	WOLF* pWlf = &wolfman;
	MAN* pMan = &wolfman;
	std::cout << ptr << "\n" << pWlf << "\n" << pMan << "\n";

	pWlf = (WOLF*)ptr; // ����ת�� void* -> WOLF*
	pMan = (MAN*)ptr;
	std::cout << ptr << "\n" << pWlf << "\n" << pMan << "\n";

	pWlf = (WOLF*)&wolfman; // ����ת�� void* -> WOLF*
	pMan = (MAN*)&wolfman;
	std::cout << ptr << "\n" << pWlf << "\n" << pMan << "\n";
	return 0;
}