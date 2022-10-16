#include<iostream>

using namespace std;

class object
{
public:
	int x;
	int y;
	object()
	{
		std::cout << "object was constructed" << std::endl;
	}

	object(const object& obj)
	{
		std::cout << "object was constructed by copy" << std::endl;
	}

	~object()
	{
		std::cout << "object was ~ deprecated." << std::endl;
	}

	void showX1()
	{
		std::cout << x << std::endl;
	}

	void showX1(int p)
	{
		std::cout << x << std::endl;
	}
};

class mapObject : public object
{
public:
	int x;
	int mapId;
	using object::showX1;
	mapObject()
	{
		x = 2500;
		object::x = 3500; // 访问的是object中的x
		std::cout << "mapObject was constructed" << std::endl;
	}
	mapObject(const mapObject& obj) :object(obj)
	{
		std::cout << "mapObject was constructed by copy" << std::endl;
	}
	mapObject(int id) :mapId(id)
	{
		std::cout << id << std::endl;
	}
	// 下面的这个函数是为了测试随便写的函数
	mapObject(int id, int id2) :mapId(id)
	{
		std::cout << id << std::endl;
	}

	~mapObject()
	{
		std::cout << "mapObject was ~deprecated." << std::endl;
	}

	void showX2()
	{
		std::cout << x << std::endl;
	}
};


class actObject : public mapObject
{
	using mapObject::mapObject; // 强制继承父类的构造函数 构造函数是不可以被子类修改访问属性的
public:

	int damage;
	actObject() : mapObject(100), damage(100) // 指定基类的构造函数
	{
		mapId = 8990;
		std::cout << "actObject was constructed" << std::endl;
	}
	actObject(const actObject& obj) : mapObject{ obj }
	{
		std::cout << "actObject was created by copy!" << std::endl;
	}
	~actObject()
	{
		std::cout << "actObject was deprecated!" << std::endl;
	}
};
// 默认构造函数 副本构造函数是不会被子类继承的
int main()
{
	mapObject MAP;

	MAP.x = 250;
	MAP.object::x = 3500; // 使用作用域解析运算符强调x是属于object类对象的 实际上MAP当中也有一个x

	MAP.showX1();
	MAP.showX2();
	return 0;
}