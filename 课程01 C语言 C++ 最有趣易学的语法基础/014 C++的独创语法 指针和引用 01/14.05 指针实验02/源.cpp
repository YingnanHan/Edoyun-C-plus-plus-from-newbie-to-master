#include<iostream>

using namespace std;

int main()
{
	int a[]{ 1001,1002,1003,1004 };
	int* ptr{ &a[0] };

	int** pptr{ &ptr };//取得指针的地址
	int*** ppptr{ &pptr };//取得指针的指针的地址

	*pptr = &a[1]; //通过pptr修改ptr的值

	cout << *ptr << endl;
	cout << **pptr << endl;
	cout << ***ppptr << endl;

	return 0;
}