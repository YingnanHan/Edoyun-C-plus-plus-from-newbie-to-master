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

	hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadId); // ���ü���+1 ��Ϊ2
	CloseHandle(hThread); // �ر����߳̾��  ���ü���-1
	handle2 = OpenThread(THREAD_QUERY_INFORMATION, FALSE, threadId); // ʹ���߳�ID���򿪶�Ӧ���߳�  ����ȥ������
	handle2 = OpenThread(THREAD_QUERY_INFORMATION, FALSE, threadId);
	handle2 = OpenThread(THREAD_QUERY_INFORMATION, FALSE, threadId);

	return 0;
}