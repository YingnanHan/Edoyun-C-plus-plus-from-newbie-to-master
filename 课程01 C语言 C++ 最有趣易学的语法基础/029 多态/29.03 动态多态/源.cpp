#include<iostream>

using namespace std;

class Animal
{
public:
	int Age;
	void virtual BeAct(Animal* animal) // 这个函数表示被其他动物攻击
	{
		cout << "动物被攻击";
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
	void virtual BeAct(Animal* animal) // 这个函数表示被其他动物攻击
	{
		cout << "人被攻击";
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

	bA->BeAct(&Dog); // 参数是随便写的，目的是为了单纯地看效果

	return 0;
}