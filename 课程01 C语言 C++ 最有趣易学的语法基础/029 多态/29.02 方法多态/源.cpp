#include<iostream>

using namespace std;

class Animal
{
public:
	int Age;
};

class Human : public Animal
{
public:
	int Money;
	void doit()
	{
		std::cout << "do it " << std::endl;
	}
};

void BeAct(Human* R)
{

}

void BeAct(Animal* animal)
{

}

int main()
{
	Human MrWang;
	Animal Dog;
	// �������صı����ʽ���ڱ����ʱ������� ---> ��̬��̬
	BeAct(&MrWang);
	BeAct(&Dog);

	return 0;
}