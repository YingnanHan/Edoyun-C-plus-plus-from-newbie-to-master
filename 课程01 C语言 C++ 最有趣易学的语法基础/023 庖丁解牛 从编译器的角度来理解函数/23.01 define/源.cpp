#include<iostream>

using namespace std;

#define _HHHH_ int // 编译器会将_HHHH_直接替换为int
#define VERSION "2.0.0"
#define SCREEN_WIDTH 1980

int main()
{
	_HHHH_ a = 10;
	cout << a << endl;
	cout << VERSION << endl;
	return 0;
}