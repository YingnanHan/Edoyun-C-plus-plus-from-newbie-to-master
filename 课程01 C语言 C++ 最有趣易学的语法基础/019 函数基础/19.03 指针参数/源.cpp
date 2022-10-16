#include<iostream>

struct Role
{
	int Mp;
	int Hp;
	int damage;
};

int Exp(const Role* r1)
{
	return r1->Hp + r1->Mp;
}

int Add(int* x, int* y)
{
	(*x) *= 100;
	(*y) *= 10;
	return (*x) + (*y);
}

bool Act(const Role* Actor, Role* beActor)
{
	beActor->Hp -= Actor->damage;
	return beActor->Hp <= 0;
}

int main()
{
	int x = 2, y = 1;
	int c = Add(&x, &y);
	std::cout << "c=" << c << "x=" << x << "y=" << y << std::endl;

	Role r1{500, 1250, 20};
	c = Exp(&r1);

	Role User{ 1000, 1500, 500212 };
	Role Monster{1500, 100, 1000};

	if (Act(&Monster, &User))
	{
		std::cout << "½ÇÉ«ËÀÍö";
	}
	else
	{
		std::cout << "¹ÖÎïËÀÍö»ñµÃÍÀÁú±¦µ¶";
	}

	return 0;
}