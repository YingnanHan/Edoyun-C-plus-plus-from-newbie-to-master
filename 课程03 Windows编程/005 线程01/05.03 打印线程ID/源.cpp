#include<stdio.h>
#include<windows.h>
#include<process.h>

DWORD WINAPI ThreadFun(LPVOID p)
{
	int iMym = *((int*)p);
	printf("���̣߳�PID = %d, iMym = %d\n", GetCurrentThreadId(), iMym);
	return 0;
}

int main()
{
	printf("main begin\n");

	HANDLE hThread;
	DWORD dwThreadID;
	int m = 0;
	hThread = CreateThread(NULL, 0, ThreadFun, &m, 0, &dwThreadID);
	printf("���̣߳�PID = %d\n", GetCurrentThreadId());
	CloseHandle(hThread); // �ر����߳̾��
	Sleep(2000);
	system("pause");
	return 0;
}