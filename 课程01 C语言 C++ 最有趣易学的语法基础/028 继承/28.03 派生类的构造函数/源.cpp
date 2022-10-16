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
};

class mapObject : public object
{
public:
	int mapId;
	mapObject()
	{
		std::cout << "mapObject was constructed" << std::endl;
	}
	mapObject(const mapObject& obj):object(obj)
	{
		std::cout << "mapObject was constructed by copy" << std::endl;
	}
	mapObject(int id) :mapId(id)
	{

	}
};


class actObject : public mapObject
{
public:
	int damage;
	actObject() : mapObject(100),damage(100) // 指定基类的构造函数
	{
		mapId = 8990;
		std::cout << "actObject was constructed" << std::endl;
	}
	actObject(const actObject& obj) : mapObject{obj}
	{
		std::cout << "actObject was created by copy!" << std::endl;
	}
};

int main()
{
	actObject obj;
	actObject obj2 = obj; //浅拷贝复制构造函数
	object x = obj; //多态

	return 0;
}