#include<iostream>

using namespace std;

class ROLE
{
public:
	int hp;
	void _stdcall BeAct(int damage) //����ͨ�����ַ�ʽ�Զ���������뷽��
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