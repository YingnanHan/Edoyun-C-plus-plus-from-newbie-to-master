#include<iostream>

using namespace std;

class Person
{
private:
	// unsigned short Age;
public:
	unsigned short Age;
	Person(int _Age) : Age(_Age)
	{

	}
};

bool Smaller(Person& psa, Person& psb)
{
	return psa.Age < psb.Age;
}

int main()
{
	Person Man(20);
	Person Woman(50);
	if (Smaller(Man, Woman))
	{
		std::cout << "ÄãÕÒ¸»ÆÅÁË£¿";
	}
	return 0;
}