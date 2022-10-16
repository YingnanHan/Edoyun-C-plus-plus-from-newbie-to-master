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

// ����ĳ�Ա����ʵ��
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
	if (Man<Woman) // <=> �ȼ���operator<(Man, Woman)
 	{
		std::cout << "���Ҹ����ˣ�";
	}
	return 0;
}