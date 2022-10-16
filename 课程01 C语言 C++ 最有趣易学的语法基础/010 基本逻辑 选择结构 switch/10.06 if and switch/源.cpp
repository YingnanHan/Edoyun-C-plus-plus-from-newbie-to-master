#include<iostream>

using namespace std;

int main()
{
	int a{ 2015 };

	if (a == 1015)
	{
		printf("a=2015");
	}
	else if (a == 2016)
	{
		printf("a=2016");
	}
	else if (a == 2017)
	{
		printf("a=2017");
	}
	else if (a == 2018)
	{
		printf("a=2018");
	}

	switch (a)
	{
	case 2015:
		printf("a=2015");
		break;
	case 2016:
		printf("a=2016");
		break;
	case 2017:
		printf("a=2017");
		break;
	case 2018:
		printf("a=2018");
		break;
	}

	return 0;
}