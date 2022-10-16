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
	// 方法重载的表达形式是在编译的时候决定的 ---> 静态多态
	BeAct(&MrWang);
	BeAct(&Dog);

	return 0;
}