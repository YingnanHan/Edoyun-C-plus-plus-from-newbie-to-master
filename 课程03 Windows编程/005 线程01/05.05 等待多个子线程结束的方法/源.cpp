#include<stdio.h>
#include<windows.h>
#include<process.h>

#define NUM_THREAD 50

unsigned WINAPI threadINC(void* arg);
unsigned WINAPI threadDEC(void* arg);

long long num = 0;

// 本函数是利用了多个函数同时处理临界区的数据，但是并没有设定互斥变量
// 所以会导致实际上最重输出的结果是不确定的
int main(int argc, char* argv[])
{
	HANDLE thandles[NUM_THREAD];
	int i;
	printf("sizeof long long :%d\n", sizeof(long long));
	for (i = 0; i < NUM_THREAD; i++)
	{
		if (i % 2 != 0)
		{
			thandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadINC, NULL, 0, NULL);
		}
		else
		{
			thandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadDEC, NULL, 0, NULL);
		}
	}
	WaitForMultipleObjects(NUM_THREAD, thandles, TRUE, INFINITE);
	printf("result: %lld\n", num);
	return 0;
}

unsigned WINAPI threadDEC(void* arg)
{
	int i;
	for (i=0;i<500000;i++)
	{
		num -= 1;
	}
	return 0;
}

unsigned WINAPI threadINC(void* arg)
{
	int i;
	for (i=0;i<500000;i++)
	{
		num += 1;
	}
	return 0;
}