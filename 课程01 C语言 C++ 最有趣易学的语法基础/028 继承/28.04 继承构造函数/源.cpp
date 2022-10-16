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
};
// 默认构造函数 副本构造函数是不会被子类继承的
int main()
{
	actObject obj{250, 350};
	actObject obj2 = obj; //浅拷贝复制构造函数
	
	//object x = obj; //多态

	return 0;
}