#include<iostream>

using namespace std;

class Animal
{
public:
	int Age;
	void virtual BeAct(Animal* animal) // ���������ʾ���������﹥��
	{
		cout << "���ﱻ����";
	}
};

class Human : public Animal
{
public:
	int Money;
	void doit()
	{
		std::cout << "do it " << std::endl;
	}
	void virtual BeAct(Animal* animal) // ���������ʾ���������﹥��
	{
		cout << "�˱�����";
	}
};


int main()
{
	Human  MrWang;
	Animal Dog;

	int id;
	Animal* bA;
	std::cin >> id;
	
	if(id)
	{
		bA = &Dog;
	}
	else
	{
		bA = &MrWang;
	}

	bA->BeAct(&Dog); // ���������д�ģ�Ŀ����Ϊ�˵����ؿ�Ч��

	return 0;
}