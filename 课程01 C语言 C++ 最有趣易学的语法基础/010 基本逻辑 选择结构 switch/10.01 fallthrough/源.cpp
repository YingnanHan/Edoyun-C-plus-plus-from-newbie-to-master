#include<iostream>

using namespace std;

int main()
{
	unsigned int sId, sPr;
	cout << "同学 请输入您的学号:";
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
		// #define fallthrough EMIT WARNING C4005
		[[fallthrough]]; // 设置故意贯穿 保证任何编译器不提醒报错
	case 321:
		sPr = sId * 2;
		break;
	default:
		sPr = 0;
		std::cout << "对不起 同学 您本次活动并没有中奖，请下次再来吧同学！\n";
		break;
	}
	if (sPr)
	{
		std::cout << "同学 恭喜您得到了奖学金 " << sPr << "韩币";
	}
	return 0;
}