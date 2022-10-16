#include<iostream>

using namespace std;

int main()
{
	int* p = new int[100];
	int* pold = p;
	p[0] = 150;

	delete[] p;
	// delete[] pold; // ÷ÿ∏¥ Õ∑≈ø’º‰

	int* m = (int*)malloc(sizeof(int) * 10);
	int* mold = m;
	m[0] = 150;

	free(m);

	return 0;
}