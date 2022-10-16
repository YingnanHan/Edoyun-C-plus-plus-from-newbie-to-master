#include<iostream>
#define NDEBUG 
// if we define this macro here(before we include header file cassert), 
// the assert in this cpp file won't work. Note :we must define macro
// before including header file cassert
#include<cassert>

using namespace std;

int main()
{
	std::cout << "请输入一个数:" << std::endl;
	int c;
	cin >> c;
	assert(c); //用于捕捉空指针或者类型错误
	return 0;
}