#include<iostream>

using namespace std;

class thingObject
{
private:
	int data_0 = 1;
	int data_1 = 2;
public:
	int data_2 = 3;
	int data_3 = 4;

	thingObject()
	{
		std::cout << "thingObject was created!" << std::endl;
	}
};

class Object
{
private:
	int data_0 = 1;
	int data_1 = 1;
public:
	int data_2 = 1;
	int data_3 = 1;

	Object()
	{
		std::cout << "Object was Created!" << std::endl;;
	}
};

class MoveObject : public Object
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

class NPC : public Object, public thingObject
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

int main()
{

	// test01 �鿴�������ݵĲ���
	Object obj;
	int* nRead = (int*)&obj;
	std::cout << "OBJ�ڴ��ַ:" << &obj << std::endl;
	for (int i = 0; i < sizeof(obj)/4; i++)
	{
		std::cout << "�ڴ��ַ:" << &nRead[i] << "ֵ:" << nRead[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	thingObject obj____;
	nRead = (int*)&obj____;
	std::cout << "OBJ____�ڴ��ַ:" << &obj____ << std::endl;
	for (int i = 0; i < sizeof(obj____) / 4; i++)
	{
		std::cout << "�ڴ��ַ:" << &nRead[i] << "ֵ:" << nRead[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// test02 �鿴�̳й�ϵ�����ݵĲ���
	MoveObject obj_;
	nRead = (int*)&obj_;
	std::cout << "OBJ_�ڴ��ַ:" << &obj_ << std::endl;
	for (int i = 0; i < sizeof(obj_) / 4; i++)
	{
		std::cout << "�ڴ��ַ:" << &nRead[i] << "ֵ:" << nRead[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// test03 �鿴�̳й�ϵ�����ݵĲ���
	NPC obj__;
	nRead = (int*)&obj__;
	std::cout << "OBJ_�ڴ��ַ:" << &obj__ << std::endl;
	for (int i = 0; i < sizeof(obj__) / 4; i++)
	{
		std::cout << "�ڴ��ַ:" << &nRead[i] << "ֵ:" << nRead[i] << std::endl;
	}

	// test04 

	return 0;
}