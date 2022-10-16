#include<iostream>

using namespace std;

class Role
{
private:
	int* ary;
public:
	Role()
	{
		ary = new int[100]; // 如果不析构那么100*4 byte大小的空间不会被析构，但是ary会被析构
		cout << "constructed!" << endl;
	}
	~Role()
	{
		delete[]ary;
		cout << "destructed" << endl;
	}
};

int main()
{
	Role user;
	int a(1);
	while (a)
	{
		std::cin >> a;
	}
	std::cout << "\nending!";
	return 0;
}