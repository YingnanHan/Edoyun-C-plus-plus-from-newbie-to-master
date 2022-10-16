#include<iostream>

using namespace std;

class Person
{
private:
	// unsigned short Age;
	friend bool operator<(Person& psa, Person& psb);
	friend bool operator<(Person& psa, unsigned short _Age);
	unsigned short Age;
public:
	Person(int _Age) : Age(_Age)
	{

	}
	unsigned short GetAge()
	{
		return this->Age;
	}
};

// 非类的成员函数实现
bool operator<(Person& psa, Person& psb)
{
	return psa.Age < psb.Age;
}

bool operator<(Person& psa, unsigned short _Age)
{
	return psa.Age < _Age;
}

int main()
{
	Person Man(20);
	Person Woman(50);
	if (Man<Woman) // <=> 等价于operator<(Man, Woman)
 	{
		std::cout << "你找富婆了？";
	}
	return 0;
}