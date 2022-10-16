#include<iostream>
#include"emath.h"
#define _VIP

void ShowWelcom()
{
#ifdef _VIP
	std::cout << "°Ö°ÖÄãºÃ";
#endif // _VIP

}

int main()
{
	int c = ave(1, 2);
	std::cout << c << std::endl;

	int d = bigger(100, 200);
	std::cout << d << std::endl;

	std::cout << acount << std::endl;

	c = atest;
	std::cout << atest;

	ShowWelcom();

	return 0;
}
