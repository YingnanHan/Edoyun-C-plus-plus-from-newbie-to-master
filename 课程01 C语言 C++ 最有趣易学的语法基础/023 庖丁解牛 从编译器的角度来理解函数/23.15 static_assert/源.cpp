#include<iostream>
#include<cassert>

using namespace std;

int main()
{

	static_assert(sizeof(int*) == 4, "������x86 32bit��������");
	return 0;
}