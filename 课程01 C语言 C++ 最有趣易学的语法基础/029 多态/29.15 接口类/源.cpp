#include<iostream>

using namespace std;

class Animal // 拥有一个纯虚函数的类叫做抽象类
{
protected:
	Animal() //建议将纯虚基类的构造函数设置为protected
	{

	}

public:
	// 除了以构造函数以外 如果一个类只定义了函数但并没有实现，那么这个类叫做接口类
	void virtual Move() = 0; // 纯虚函数
	void virtual Fly() = 0; // 纯虚函数
};

class Dog : public Animal
{
	void virtual Move()
	{

	}
	// 如果子类并没有实现父类的所有内容，那么它就会变成一个虚类
};

class Cat :public Animal
{
	void virtual Move()
	{

	}
};



int main()
{
	// Animal ani; // 抽象类不可以定义对象 以及函数实体
	// Animal* cat = new Cat();

	return 0;
}