#include<stdio.h>
#include<windows.h>
#include<WinBase.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	printf("I am comimng...");
	while (1)
	{

	}
	return 0;
}

int main()
{
	HANDLE hThread;
	HANDLE handle2;
	DWORD threadId;

	hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadId); // 引用计数+1 变为2
	CloseHandle(hThread); // 关闭了线程句柄  引用计数-1
	handle2 = OpenThread(THREAD_QUERY_INFORMATION, FALSE, threadId); // 使用线程ID来打开对应的线程  或者去访问它
	handle2 = OpenThread(THREAD_QUERY_INFORMATION, FALSE, threadId);
	handle2 = OpenThread(THREAD_QUERY_INFORMATION, FALSE, threadId);

	return 0;
}