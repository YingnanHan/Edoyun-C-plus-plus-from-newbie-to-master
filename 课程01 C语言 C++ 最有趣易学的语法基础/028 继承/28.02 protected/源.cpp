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
		x = 200; // �ⲿ���ʲ���x
		t = 200;
	}
};

class ActObject : public MoveObject
{
public:
	// ���޸ĵ��ҽ����ڱ�����Է���
	using MoveObject::getHP; // ͨ����public����˵��vip��ʹ��vip�仯Ϊpublic
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