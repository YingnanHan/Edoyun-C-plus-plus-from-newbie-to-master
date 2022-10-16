#include<iostream>

using namespace std;

class Object
{
private:
	int data_0 = 1;
	int data_1 = 2;
public:
	int data_2 = 3;
	int data_3 = 4;

	Object()
	{
		std::cout << "Object was Created!" << std::endl;;
	}
};


class thingObject : public virtual Object
{
private:
	int tdata_0 = 81;
	int tdata_1 = 82;
public:
	int tdata_2 = 83;
	int tdata_3 = 84;

	thingObject()
	{
		std::cout << "thingObject was created!" << std::endl;
	}
};

class MoveObject : public virtual Object
{
private:
	int Mdata_0 = 21;
	int Mdata_1 = 22;
public:
	int Mdata_2 = 23;
	int Mdata_3 = 24;
	MoveObject()
	{
		std::cout << "MoveObject was Created!" << std::endl;;
	}
};

class NPC : public virtual MoveObject, public virtual thingObject
{
private:
	int Ndata_0 = 21;
	int Ndata_1 = 22;
public:
	int Ndata_2 = 23;
	int Ndata_3 = 24;
	NPC()
	{
		std::cout << "NPC was Created!" << std::endl;;
	}
};

// 以上的各类构成了菱形继承关系
/*
			  Object
	     ↙			   ↘
	MoveObject		thingObject
		 ↘			   ↙
			   NPC
*/

int main()
{
	NPC obj;

	int* nRead = (int*)&obj;
	std::cout << "OBJ内存地址:" << &obj << std::endl;
	for (int i = 0; i < sizeof(obj) / 4; i++)
	{
		std::cout << "内存地址:" << &nRead[i] << "值:" << nRead[i] << std::endl;
	}

	return 0;
}