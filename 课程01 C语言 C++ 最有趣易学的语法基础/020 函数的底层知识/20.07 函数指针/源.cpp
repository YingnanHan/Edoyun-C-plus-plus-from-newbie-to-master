#include<iostream>

using namespace std;

typedef char(*pfAdd)(int, int); // 声明一个函数指针类型
using pfAdd = char(*)(int, int); // 声明一个函数指针类型
using pRole = int(*)(int hp, int mp); // 声明一个函数指针类型

int AddX(int a, int b)
{
	return a * 10 + b;
}

float Add(int a, int b)
{
	return (a + b)/2;
}

struct Role
{
	int hp;
	int mp;
};

int Exp(Role r1)
{
	return r1.hp + r1.mp;
}

int main()
{
	// 01
	int(*pAdd)(int, int) {(int(*)(int, int))Add}; // 定义一个函数指针 (int(*)(int, int))将Add转化为指定类型
	cout << pAdd(1, 1) << std::endl; //输出得到的返回值是以int来表现的 声明一个函数指针
	cout << sizeof pAdd << std::endl;
	
	// 02
	char(*pAdd_)(int, int) { (char(*)(int, int))Add };
	cout << pAdd_(1, 1) << std::endl; //输出得到的返回值是以char来表现的

	// 03
	using pFadd = char(*)(int, int); // 声明函数指针类型
	pFadd pFadd1 = (pFadd)pAdd;
	pFadd1(1, 1);
	
	// 04 打分程序
	struct Role r { 100, 100 };
	cout << Exp(r) << endl;

	// 05 
	Role r1{ 100, 350 };
	pRole pExp = (pRole)Exp;
	cout << pExp(100, 350); //注意这里对参数的解释，实际上就是对内存地址的理解
	return 0;
}