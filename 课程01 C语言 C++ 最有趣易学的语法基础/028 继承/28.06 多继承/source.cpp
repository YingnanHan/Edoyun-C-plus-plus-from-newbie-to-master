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

class WolfMan : public Wolf, public Man //���μ̳�
{
public:
	void Change() // ����
	{
		IsWolf = !IsWolf;
		std::cout << "����!" << std::endl;
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

	using Wolf::eat; // Ĭ��ʹ�õ���Wolf�µ�eat
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

	////  /*method 01*/ Jack.Wolf::eat(); // ǿ��ʹ�õ���Wolf�µ�eat
	//
	////  /*method 02*/ Jack.eat();

	///*method 03*/
	//Jack.Change();
	//Jack.eat();

	// -----------------------------
	// part 02
	
	 
	//WolfMan Jack;
	//Jack.bite();
	//// Jack.x = 250; // Wolfman::x ����ȷ
	//Jack.Wolf::x = 250; // Wolf.x �� Man.x��һ����ʵ�������ڴ�ռ����ǲ�һ����
	//Jack.Wolf::y = 250;
	//std::cout << "(" << Jack.Wolf::x << "," << Jack.Wolf::y << ")" << std::endl;

	// -----------------------------
	// part 03

	// �����������ķ����ǽ�Object����Ϊ����࣬��ʾ�����μ̳й�ϵͼ����ֻ����һ��
	WolfMan Jack;
	Jack.x = 250;
	Jack.y = 250;
	std::cout << "(" << Jack.x << "," << Jack.y << ")" << std::endl;

	return 0;
}