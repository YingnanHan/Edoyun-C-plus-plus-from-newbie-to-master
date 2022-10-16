#include<iostream>

using namespace std;

int main()
{
	int a[5] = { 1001,1002,1003,1004,1005 };

	int* b = new int[5];

	memset(a, 0xff, 4 * 5); //由于是按照字节来操作的 所以设置内存的时候是传递的字节
	memcpy(b, a, 20);

	for (int i = 0; i < 5; i++)
	{
		std::cout << hex << b[i] << std::endl;
	}

	return 0;
}