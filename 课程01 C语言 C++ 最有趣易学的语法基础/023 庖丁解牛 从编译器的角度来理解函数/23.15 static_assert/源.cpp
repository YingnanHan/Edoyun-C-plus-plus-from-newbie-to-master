#include<iostream>
#include<cassert>

using namespace std;

int main()
{

	static_assert(sizeof(int*) == 4, "必须在x86 32bit环境编译");
	return 0;
}