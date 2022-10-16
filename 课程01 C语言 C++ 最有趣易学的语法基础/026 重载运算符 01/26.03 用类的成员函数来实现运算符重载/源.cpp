#include<iostream>

using namespace std;

class Person
{
private:
	// unsigned short Age;
	friend bool operator<(const Person& psa, const Person& psb);
	friend bool operator<(const Person& psa, const unsigned short _Age);
	unsigned short Age;
public:
	Person(int _Age) : Age(_Age)
	{

	}
	unsigned short GetAge()
	{
		return this->Age;
	}
	bool bigger(Person& person)
	{
		return Age > person.Age;
	}
	bool operator>(Person& person)
	{
		return Age > person.Age;
	}
};

// 非类的成员函数实现
bool operator<(const Person& psa, const Person& psb)
{
	return psa.Age < psb.Age;
}

bool operator<(const Person& psa, const unsigned short _Age)
{
	return psa.Age < _Age;
}

int main()
{
	Person Man(200);
	Person Woman(50);
	if (Man > Woman) // <=> 等价于operator<(Man, Woman)
	{
		std::cout << "你找富婆了？";
	}
	return 0;
}