#include<iostream>

using namespace std;

//class Xobject // nickname
//{
//public:
//	char Name[0x20]; // define as nickname
//};

class object // final // final���ڽ�ֹ�̳� final�ǿ�������������������
{
public:
	char Name[0x20];
};

class mapObject : public object
{
public:
	int x;
	int y;
//private:
//	int t; // ����̳��Ժ󲻿ɵ��ã�����ȷʵռ������ռ�
protected:
	int t;
};

class MoveObject : public mapObject
{
private:
	int hp;
	int lv;
protected:
	int vip;	// ��һ���ֽ������Ա���Ԫ���� ��Ԫ�� �������
public:
	MoveObject()
	{
		// t = 20; // ���ɷ��� if t was decorated by private
		t = 200;
	}
};

int main()
{
	// 01
	//mapObject tree; // 1
	//tree.x = 200;

	// std::cout << sizeof(MoveObject); // 8byte


	// 02
	MoveObject npc;
	// npc.vip; // ���ɷ���
	return 0;
}