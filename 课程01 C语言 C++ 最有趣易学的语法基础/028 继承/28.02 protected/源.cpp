#include<iostream>

using namespace std;

class object 
{
public:
	char Name[0x20];
};

class mapObject : public object
{
public:
	int x;
	int y;

	int getMapId()
	{
		return this->mapId;
	}

	void setMapId(int val)
	{
		this->mapId = val;
	}
protected:
	int t;
private:
	int xxx;
private:
	int mapId;
};

class MoveObject : /*protected*/ private mapObject
{
private:
	
	int hp;
	int lv;
protected:
	int vip;
	int getHP(int x2)
	{
		hp = x2;
	}
public:
	MoveObject()
	{
		x = 200; // 外部访问不了x
		t = 200;
	}
};

class ActObject : public MoveObject
{
public:
	// 可修改当且仅当在本类可以访问
	using MoveObject::getHP; // 通过在public当中说明vip会使得vip变化为public
	ActObject()
	{
		/*x = 200;
		y = 200;
		t = 200;*/
	}
};

int main()
{

	return 0;
}