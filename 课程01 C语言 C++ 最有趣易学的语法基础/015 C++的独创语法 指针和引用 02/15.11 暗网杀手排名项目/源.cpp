#include<iostream>

using namespace std;

int main()
{
	//57
	// int a[10] = {105, 98, 73, 58, 32, 31, 25, 22, 3, 1};
	int a[10] = { 1,3,22,25,31,32,58,73,98,105 };
	// int anew[11] = {1,3,22,25,31,32,58,73,98,105};
	int account = sizeof(a) / sizeof(int);
	int* anew = new int[account + 1];

	int x;
	std::cout << "输入新杀手臭名值:";
	std::cin >> x;

	int getIndex{ account };

	bool bcase = a[0] > a[1];

	for (int i = 0; i < account; i++)
	{
		if (bcase ^ (x < a[i]))
		{
			getIndex = i;
			break;
		}
	}

	memcpy(anew, a, getIndex * sizeof(int));
	memcpy(anew + getIndex + 1, a + getIndex, (account - getIndex) * sizeof(int));
	anew[getIndex] = x;
	for (int i = 0; i <= account; i++)
	{
		std::cout << anew[i] << std::endl;
	}

	return 0;
}