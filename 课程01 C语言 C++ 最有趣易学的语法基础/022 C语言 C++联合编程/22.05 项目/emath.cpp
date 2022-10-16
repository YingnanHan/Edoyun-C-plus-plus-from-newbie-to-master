#include"emath.h"

int account{ 250 };
extern int atest; //外部引入的对象要使用static声明

int ave(int a, int b)
{
	account++;
	atest++;
	return (a + b) / 2;
}

int bigger(int a, int b)
{
	return a > b ? a : b;
}