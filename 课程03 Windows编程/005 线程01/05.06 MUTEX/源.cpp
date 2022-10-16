#include<stdio.h>
#include<windows.h>
#include<process.h>

#define NUM_THREAD 50

unsigned WINAPI threadINC(void* arg);
unsigned WINAPI threadDEC(void* arg);

long long num = 0;

HANDLE hMutex; // ���廥������ľ�� (����һ����־)

// �������������˶������ͬʱ�����ٽ��������ݣ����ǲ�û���趨�������
// ���Իᵼ��ʵ������������Ľ���ǲ�ȷ����
int main(int argc, char* argv[])
{
	HANDLE thandles[NUM_THREAD];
	int i;
	/*
	HANDLE CreateMutex(
			LPSECURITY_ATTRIBUTES lpMutexAttributes, // ָ��ȫ���Ե�ָ��
			BOOL bInitialOwner,						 // ��ʼ����������������
			LPCTSTR lpName							 // ָ�򻥳��������ָ��
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
// ��������ı��ʾ��Ǽ����������ڷ����ٽ�����ʱ�򻥳��¼��ķ���
unsigned WINAPI threadDEC(void* arg)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE); // �ȴ���������Ϊ��֪ͨ״̬
	for (i = 0; i < 500000; i++)
	{
		num -= 1;
	}
	ReleaseMutex(hMutex); // �ͷŻ�����
	return 0;
}

unsigned WINAPI threadINC(void* arg)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE); // �ȴ���������Ϊ��֪ͨ״̬
	for (i = 0; i < 500000; i++)
	{
		num += 1;
	}
	ReleaseMutex(hMutex); // �ͷŻ�����
	return 0;
}