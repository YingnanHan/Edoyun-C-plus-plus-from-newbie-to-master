#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

using namespace std;

// ����̵߳ȴ�����

DWORD WINAPI ThreadFun(LPVOID arg) // ����ȼ���void*
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
	// һ�������������ʱ�����߳̽����Ժ��ӽ��̿��ܲ�û�н��������߳���Ҫ�ȴ��ӽ��̽�����ſ���ִ�к����������ֹ����
	// ������Ҫ���µĲ������������̵߳ȴ����̵߳Ľ���
	printf("##################### Beginning Waiting for Single Object #####################\n");
	if ((wr = WaitForSingleObject(hThread, INFINITE)) == WAIT_FAILED) // �ȴ�һ�����߳̽��� ���߳����������� ֪���ں˶����ʶ�����߳̾������֪ͨ״̬�ķ���
	{
		puts("thread wait error");
		return -1;
	}
	CloseHandle(hThread);
	printf("##################### Ending Waiting for Single Object #####################\n");
	system("pause");
	return 0;
}

