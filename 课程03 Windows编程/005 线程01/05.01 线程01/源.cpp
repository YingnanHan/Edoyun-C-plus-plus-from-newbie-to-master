#include<stdio.h>
#include<windows.h>

int main_hong(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("push-up\n");
		Sleep(3000);
	}
	return 0;
}

int main_ming(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("shake head\n");
		Sleep(4000);
	}
	return 0;
}

int main_wang(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("singing\n");
		Sleep(3000);
	}
	return 0;
}

int main()
{
	int hong = 20;
	int ming = 30;
	int wang = 50;

	main_hong(hong);
	main_ming(ming);
	main_wang(wang);

	system("pause");
	return 0;
}