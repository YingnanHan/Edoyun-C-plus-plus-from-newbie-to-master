#include<iostream>

using namespace std;

class Role
{
private:
	int* ary;
public:
	Role()
	{
		ary = new int[100]; // �����������ô100*4 byte��С�Ŀռ䲻�ᱻ����������ary�ᱻ����
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