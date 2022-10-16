#include<iostream>

using namespace std;

class ROLE
{
public:
	int hp;
	void _stdcall BeAct(int damage) //可以通过这种方式自定义参数传入方法
	{
		hp -= damage;
		std::cout << "BeAct:" << damage << std::endl;
	}
};

int main()
{
	ROLE player;
	player.BeAct(20);// this call

	return 0;
}