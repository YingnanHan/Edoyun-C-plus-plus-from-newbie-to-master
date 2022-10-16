#include<iostream>

using namespace std;

//class Xobject // nickname
//{
//public:
//	char Name[0x20]; // define as nickname
//};

class object // final // final用于禁止继承 final是可以用来做变量的名的
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
//	int t; // 子类继承以后不可调用，但是确实占用子类空间
protected:
	int t;
};

class MoveObject : public mapObject
{
private:
	int hp;
	int lv;
protected:
	int vip;	// 这一部分仅仅可以被友元函数 友元类 子类访问
public:
	MoveObject()
	{
		// t = 20; // 不可访问 if t was decorated by private
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
	// npc.vip; // 不可访问
	return 0;
}