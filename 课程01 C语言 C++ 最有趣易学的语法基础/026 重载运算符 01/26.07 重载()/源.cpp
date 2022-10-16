#include<iostream>
#include"hstring.h"

using namespace std;

int main()
{
	hstring str = "a123";
	hstring xstr = str(1, 2);
	std::cout << xstr;

	return 0;
}