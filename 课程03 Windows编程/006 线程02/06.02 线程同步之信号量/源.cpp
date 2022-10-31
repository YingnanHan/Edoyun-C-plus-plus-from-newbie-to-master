#include<stdio.h>
#include<windows.h>
#include<process.h>

static HANDLE semOne;
static HANDLE semTwo;
static int num;

unsigned WINAPI Read(void* arg)
{
	int i;
	for (i=0;i<5;i++)
	{
		fputs("Input num:", stdout);
		printf("begin read\n");
		//等待内核对象semTwo的信号量，如果有信号，继续执行；如果没有信号，等待
		WaitForSingleObject(semTwo, INFINITE);
		printf("beginning read\n");
		scanf_s("%d", &num);
		ReleaseSemaphore(semOne, 1, NULL);
	}
	return 0;
}

unsigned WINAPI Accu(void* arg)
{
	int sum = 0, i;
	for (i = 0; i < 5; i++)
	{
		printf("begin Accu\n");
		WaitForSingleObject(semOne, INFINITE);
		printf("beginning Accu\n");
		sum += num;
		printf("sum = %d \n", sum);
		ReleaseSemaphore(semTwo, 1, NULL);
	}
	printf("Result: %d\n", sum);
	return 0;
}

int main()
{
	HANDLE hThread1, hThread2;
	semOne = CreateSemaphore(NULL, 0, 1, NULL);
	// semOne 没有可用资源 只能表示0或者1的二进制信号量 无信号
	semTwo = CreateSemaphore(NULL, 1, 1, NULL);
	// semOne 有可用资源 有信号状态 有信号
	hThread1 = (HANDLE)_beginthreadex(NULL, 0, Read, NULL, 0, NULL);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, Accu, NULL, 0, NULL);

	WaitForSingleObject(hThread2, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	CloseHandle(hThread1);
	CloseHandle(hThread2);

	return 0;
}