#include<iostream>

using namespace std;

class DOG
{

};

class WOLF
{
public:

	static void count()
	{

	}

	WOLF()
	{

	}

	void GrowUP0()
	{
		std::cout << "�ɳ�����һ�׶�!" << std::endl;
	}

	void GrowUP1()
	{
		std::cout << "�ɳ����˶��׶�!" << std::endl;
	}

	void GrowUP2()
	{
		std::cout << "�ɳ��������׶�!" << std::endl;
	}
};

typedef void (WOLF::*PGOURP)(); //����һ��WOLF���͵ĺ���ָ��

void X()
{

}

typedef void(*COUNT)(); //��ľ�̬��Աû��thisָ�룬���Կ��԰���������ͨ������ʹ��

int main()
{
	PGOURP pFunction = &WOLF::GrowUP0; // ��ȡ����ָ��
	WOLF* pWolf = new WOLF();
	DOG* pDog = new DOG();
	(pWolf->*pFunction)();
	// (pDog->*pFunction)(); //����

	COUNT _count = &WOLF::count; // ��ȡ��̬������ָ��
	_count();
	return 0;
}