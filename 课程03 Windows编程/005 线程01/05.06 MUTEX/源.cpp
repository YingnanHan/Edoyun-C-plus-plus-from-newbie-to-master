#include<stdio.h>
#include<windows.h>
#include<process.h>

#define NUM_THREAD 50

unsigned WINAPI threadINC(void* arg);
unsigned WINAPI threadDEC(void* arg);

long long num = 0;

HANDLE hMutex; // 定义互斥变量的句柄 (就是一个标志)

// 本函数是利用了多个函数同时处理临界区的数据，但是并没有设定互斥变量
// 所以会导致实际上最重输出的结果是不确定的
int main(int argc, char* argv[])
{
	HANDLE thandles[NUM_THREAD];
	int i;
	/*
	HANDLE CreateMutex(
			LPSECURITY_ATTRIBUTES lpMutexAttributes, // 指向安全属性的指针
			BOOL bInitialOwner,						 // 初始化互斥对象的所有者
			LPCTSTR lpName							 // 指向互斥对象名的指针
		);
	*/
	hMutex = CreateMutex(NULL, FALSE, NULL); // 
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
	CloseHandle(hMutex);
	printf("result: %lld\n", num);
	return 0;
}
// 下面操作的本质就是加锁，导致在访问临界区的时候互斥事件的发生
unsigned WINAPI threadDEC(void* arg)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE); // 等待互斥量变为已通知状态
	for (i = 0; i < 500000; i++)
	{
		num -= 1;
	}
	ReleaseMutex(hMutex); // 释放互斥量
	return 0;
}

unsigned WINAPI threadINC(void* arg)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE); // 等待互斥量变为已通知状态
	for (i = 0; i < 500000; i++)
	{
		num += 1;
	}
	ReleaseMutex(hMutex); // 释放互斥量
	return 0;
}