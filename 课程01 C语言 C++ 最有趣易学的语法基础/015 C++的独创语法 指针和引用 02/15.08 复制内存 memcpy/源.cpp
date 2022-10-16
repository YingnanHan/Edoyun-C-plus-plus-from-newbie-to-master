#include<iostream>

using namespace std;

int main()
{
	int a[5]{ 1001,1002,1003,1004,1005 };
	int* b = new int[5];
	memcpy(b, a, 5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << " " << std::ends;
	}

	return 0;
}