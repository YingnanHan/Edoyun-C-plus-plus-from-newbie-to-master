#include<iostream>

using namespace std;

class MoveObject
{
public:
	int x;
	int y;

	void virtual move() // 向斜上方走
	{
		x++;
		y++;
	}
};

class NPCObject : public MoveObject
{
public:
	void virtual move() override // 向斜上方走 但凡是派生类的虚函数最好写上override关键字做声明
	{
		x++;
		y++;
		std::cout << "I'm NPC" << std::endl;
	}
};

class MonsterObject final : public NPCObject
{
public:
	void virtual move() override
	{
		x++;
		y++;
		std::cout << "I'm Monster" << std::endl;
	}
};

// 01 老式重载性质的写法
//void Move(MonsterObject* obj)
//{
//	obj->move();
//}
//
//void Move(NPCObject* obj)
//{
//	obj->move();
//}

// 02 使用多态
void Move(MoveObject* obj) //这里必须使用引用或者指针
{
	obj->move();
}

class SNPObject : public MoveObject
{
public:
	void virtual move() override
	{
		x++;
		y++;
		std::cout << "";
		return; //0表示空指针
	}
};

int main()
{
	MonsterObject anaconda;
	NPCObject     npc;

	Move(&anaconda);		// 动态绑定
	Move(&npc);				// 动态绑定

	return 0;
}

/* 关于虚函数的解说
	1. virtual只能写在类的内部声明或者定义，不能把virtual写在类外部的定义当中
	2. 调用类的对象是无法使用虚函数的，必须使用基类指针来实现虚函数的调用
	3. 虚函数在派生类和基类中必须拥有相同的函数声明以及参数列表
	4. 虚函数在派生类和基类中返回值要求基本一致[但是当返回值类型为指针和引用时除外->协变的情况下可以编译 (返回值必须处于同一继承关系中间)]
	5. 虚函数不能是函数模板
*/
