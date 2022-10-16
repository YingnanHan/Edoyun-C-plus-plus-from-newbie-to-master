#include<iostream>

using namespace std;

class MoveObject
{
public:
	int x;
	int y;
};

class Wolf : virtual public MoveObject
{
public:
	void eat()
	{
		std::cout << "Wolf eat";
	}

	void bite()
	{
		std::cout << "Wolf bite";
	}
};

class Man : virtual public MoveObject
{
public:
	void eat()
	{
		std::cout << "Man Eat";
	}
};

class WolfMan : public Wolf, public Man //菱形继承
{
public:
	void Change() // 变身
	{
		IsWolf = !IsWolf;
		std::cout << "变身!" << std::endl;
	}

	void eat() // method 03
	{
		if (IsWolf)
		{
			Wolf::eat();
		}
		else
		{
			Man::eat();
		}
	}

	using Wolf::eat; // 默认使用的是Wolf下的eat
private:
	bool IsWolf = false;
};

int main()
{
	// part 01
	 
	
	//WolfMan Jack;
	//Jack.bite();
	//Jack.eat();
	//cout << "\n";

	////  /*method 01*/ Jack.Wolf::eat(); // 强调使用的是Wolf下的eat
	//
	////  /*method 02*/ Jack.eat();

	///*method 03*/
	//Jack.Change();
	//Jack.eat();

	// -----------------------------
	// part 02
	
	 
	//WolfMan Jack;
	//Jack.bite();
	//// Jack.x = 250; // Wolfman::x 不明确
	//Jack.Wolf::x = 250; // Wolf.x 与 Man.x不一样，实际上在内存空间上是不一样的
	//Jack.Wolf::y = 250;
	//std::cout << "(" << Jack.Wolf::x << "," << Jack.Wolf::y << ")" << std::endl;

	// -----------------------------
	// part 03

	// 解决上面问题的方法是将Object设置为虚基类，表示在菱形继承关系图中他只出现一次
	WolfMan Jack;
	Jack.x = 250;
	Jack.y = 250;
	std::cout << "(" << Jack.x << "," << Jack.y << ")" << std::endl;

	return 0;
}