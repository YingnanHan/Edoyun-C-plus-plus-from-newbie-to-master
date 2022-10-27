#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

using namespace std;

// 解决线程等待问题

DWORD WINAPI ThreadFun(LPVOID arg) // 这里等价于void*
{
	int cnt = *((int*)arg);
	for (int i = 0; i < cnt; i++)
	{
		printf("sleep\n");
		Sleep(1000);
	}
	return 0;
}

int main()
{
	printf("main begin\n");
	int wr;
	HANDLE hThread;
	DWORD dwThreadID;
	int m = 5;
	hThread = CreateThread(NULL, 0, &ThreadFun, &m, 0, &dwThreadID);
	// 一般来讲，在这个时候主线程结束以后，子进程可能并没有结束，主线程需要等待子进程结束后才可以执行后续自身的终止操作
	// 于是需要以下的操作，命令主线程等待子线程的结束
	printf("##################### Beginning Waiting for Single Object #####################\n");
	if ((wr = WaitForSingleObject(hThread, INFINITE)) == WAIT_FAILED) // 等待一个子线程结束 主线程阻塞在这里 知道内核对象标识的子线程句柄的已通知状态的发生
	{
		puts("thread wait error");
		return -1;
	}
	CloseHandle(hThread);
	printf("##################### Ending Waiting for Single Object #####################\n");
	system("pause");
	return 0;
}

