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

int main()
{
	// test 01

	//Human MrWang{};
	//MrWang.Age = 350;
	//MrWang.Money = 520;
	//Animal animal = MrWang; // 内存切片初始化 将来涉及到函数的话不建议这样写
	//std::cout << animal.Age << std::endl; // 向上转型


	// test 02

	Human MrWang{};
	MrWang.Age = 350;
	MrWang.Money = 520;
	// 向上转型
	Animal *animal = &MrWang; // 实际上应该使用指针或者引用来进行转化
	std::cout << animal->Age << std::endl; 
	// 向下转型
	Human* human = (Human*)animal; //强制性的向下转型，其主要目的是调用animal里面的函数
	human->doit(); // 如果doit()里面含有访问子类特有的东西，那么不推荐使用



	return 0;
}