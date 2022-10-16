#include<iostream>

using namespace std;

union
{
	short	sHP;
	int		nHP;
	double	fHP;
} ls; //匿名共用体 但是不可以重复使用

struct
{
	int size;
} ss; //匿名结构体 与匿名共用体相同 用于临时创建对象

// 假设在其他数据结构中会使用到Union并且仅仅是用一次那么就会使用到匿名联合体

int main()
{
	ss.size = 10;
	cout << ss.size << endl;
	return 0;
}