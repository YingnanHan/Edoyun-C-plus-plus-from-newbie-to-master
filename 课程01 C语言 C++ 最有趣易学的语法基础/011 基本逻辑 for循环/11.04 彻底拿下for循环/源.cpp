#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	bool bcase{};
	for (int i = 3; i < 1000; i += 2)
	{
		bcase = false;
		for (int c = 3; c < sqrt(i); c += 2)
		{
			if (i % c == 0)
			{
				bcase = true;
				break;
			}
		}
		if (!bcase)
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}