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
	//���ָ������
	MoveObject* _move = new MoveObject();
	_move = new Monster();
	std::cout << typeid(*_move).name();

	std::cout << std::endl;

	//������õ����
	MoveObject wolf;
	MoveObject& lMove = wolf;
	std::cout << typeid(lMove).name() << std::endl;;	// ���ò���Ҫ��ԭ ������

	// typeid�����������ж�
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