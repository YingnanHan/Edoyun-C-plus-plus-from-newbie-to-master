#include<iostream>

using namespace std;

int main()
{
	unsigned int sId, sPr;
	cout << "ͬѧ ����������ѧ��:";
	std::cin >> sId;

	switch (sId)
	{
	case 15692:
		sPr = 500;
		break;
	case 65421:
		sPr = 650;
		break;
	case 98741:
		sPr = 250;
		break;
	case 2531:
		sPr = 150;
		break;
	case 666:
	case 321:
		sPr = sId * 2;
		break;
	default:
		sPr = 0;
		std::cout << "�Բ��� ͬѧ �����λ��û���н������´�������ͬѧ��\n";
		break;
	}
	if (sPr)
	{
		std::cout << "ͬѧ ��ϲ���õ��˽�ѧ�� " << sPr << "����";
	}
	return 0;
}