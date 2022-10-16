#include<iostream>

using namespace std;

//auto bigger(int&& a, int&& b) -> decltype(a > b ? a : b)
//{
//	return a > b ? a : b;
//}

decltype(auto) bigger(int&& a, int&& b) // C++14Ð´·¨
{
	return a > b ? a : b;
}

int main()
{
	cout << bigger(1, 12);
	return 0;
}