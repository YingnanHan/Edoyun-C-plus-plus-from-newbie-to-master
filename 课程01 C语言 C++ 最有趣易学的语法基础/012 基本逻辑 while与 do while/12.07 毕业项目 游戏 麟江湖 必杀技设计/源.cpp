#include<iostream>

using namespace std;

int main()
{
	int Mp{ 1383 }, lsMp{ Mp };
	int damage{}, needMp{};
	do
	{
		damage += 100;
		Mp -= needMp;
		needMp += 50;
		std::cout << "����˺�" << damage << "ʣ��MP:" << Mp << std::endl;;

	} while (Mp >= needMp);
	Mp = lsMp;
	return 0;
}