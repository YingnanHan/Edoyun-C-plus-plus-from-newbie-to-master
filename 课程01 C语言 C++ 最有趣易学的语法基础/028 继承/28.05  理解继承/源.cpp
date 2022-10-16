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
		object::x = 3500; // ���ʵ���object�е�x
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
	// ��������������Ϊ�˲������д�ĺ���
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
	using mapObject::mapObject; // ǿ�Ƽ̳и���Ĺ��캯�� ���캯���ǲ����Ա������޸ķ������Ե�
public:

	int damage;
	actObject() : mapObject(100), damage(100) // ָ������Ĺ��캯��
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
// Ĭ�Ϲ��캯�� �������캯���ǲ��ᱻ����̳е�
int main()
{
	mapObject MAP;

	MAP.x = 250;
	MAP.object::x = 3500; // ʹ����������������ǿ��x������object������ ʵ����MAP����Ҳ��һ��x

	MAP.showX1();
	MAP.showX2();
	return 0;
}