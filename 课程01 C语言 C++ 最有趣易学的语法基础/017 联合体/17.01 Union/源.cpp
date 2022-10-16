#include<iostream>

using namespace std;

union USER
{
	short	sHP;
	int		nHp;
	double	fHp;
};

int main()
{
	USER user; // [][][][][][][][] 直接分配八个字节 但是并没有初始化
	std::cout << sizeof user << std::endl;

	// 首先初始化
	user.nHp = 0;
	user.sHP = -1; // [0xff][0xff][][][][][][]
	std::cout << &user.sHP << std::endl;
	// 内存地址是相同的 所以联合体是共享内存空间的
	// [100][0][?][?][?][?][?][?]
	std::cout << &user.nHp << std::endl;
}