#include <stdio.h>
#include <windows.h>
#include <process.h>

char str[100];
HANDLE hEvent;

// ������ĸ�ַ��� ʹ���߳�ͬ���ķ�ʽ��ʵ���м�����ĸA

unsigned WINAPI NumberOfAs(void* arg)
{
	int i, cnt = 0;
	WaitForSingleObject(hEvent, INFINITE);
	for (i=0;str[i]!=0;i++)
	{
		if (str[i] == 'A')
		{
			cnt++;
		}
	}
	printf("Number of A = %d", cnt);
	return 0;
}
unsigned WINAPI NumberOfOthers(void* arg)
{
	int i, cnt = 0;
	// WaitForSingleObject(hEvent, INFINITE);
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] != 'A')
		{
			cnt++;
		}
	}
	printf("Number of others = %d", cnt-1);
	SetEvent(hEvent); // ���¼�����Ϊ���ź�״̬�������Ǹ������Ż�ִ��
	return 0;
}

int main()
{
	HANDLE hThread1, hThread2;
	fputs("Input string:\n", stdout);
	fgets(str, 100, stdin);
	/*
		HANDLECreateEvent(
			LPSECURITY_ATTRIBUTESlpEventAttributes,	// ��ȫ����
			BOOLbManualReset,						// ��λ��ʽ True������ResetEvent�ֶ���ԭ
			BOOLbInitialState,						// ��ʼ״̬ True��ʼ״̬Ϊ���ź�״̬�� FalseΪ���ź�״̬
			LPCTSTRlpName							// �������� NULL �������¼���������
		);

		lpEventAttributes[����]
					һ��ָ��SECURITY_ATTRIBUTES�ṹ��ָ�룬ȷ�����صľ���Ƿ�ɱ��ӽ��̼̳С����lpEventAttributes��NULL���˾�����ܱ��̳С�
					Windows NT/2000��lpEventAttributes�Ľṹ�еĳ�ԱΪ�µ��¼�ָ����һ����ȫ�������lpEventAttributes��NULL���¼������һ��Ĭ�ϵİ�ȫ����
		bManualReset[����]
					ָ�����¼����󴴽����ֶ���ԭ�����Զ���ԭ�������TRUE����ô������ResetEvent�������ֹ����¼���״̬��ԭ�����ź�״̬���������ΪFALSE����һ���̵߳ȴ����¼��źź�ϵͳ���Զ����¼�״̬��ԭΪ���ź�״̬��
		bInitialState[����]
					ָ���¼�����ĳ�ʼ״̬�����ΪTRUE����ʼ״̬Ϊ���ź�״̬������Ϊ���ź�״̬��
		lpName[����]
					ָ���¼��Ķ�������ƣ���һ����0�������ַ���ָ�롣���Ƶ��ַ���ʽ�޶���MAX_PATH֮�ڡ������ǶԴ�Сд���еġ�
					���lpNameָ�������֣���һ�����ڵ��������¼������������ͬ������������EVENT_ALL_ACCESS�����ʴ��ڵĶ�����ʱ������bManualReset��bInitialState�����Ѿ��ڴ����¼��Ľ��������ã������������������ԡ����lpEventAttributes�ǲ�������NULL������ȷ���˾���Ƿ���Ա��̳У������䰲ȫ��������Ա�������ԡ�
					���lpNameΪNULL��������һ���������¼�����
					���lpName�ĺ�һ�����ڵ��źš����⡢�ȴ���ʱ������ҵ�������ļ�ӳ�����������ͬ����������ʧ�ܣ���GetLastError�����н�����ERROR_INVALID_HANDLE��������������ԭ������Щ������ͬһ�������ռ䡣
	*/
	// ����һ���Զ����õ��¼����������ʼֵΪ���ź�״̬FALSE
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	hThread1 = (HANDLE)_beginthreadex(NULL, 0, NumberOfAs, NULL, 0, NULL);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, NumberOfOthers, NULL, 0, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	// ֱ�������߳���ȫִ�����֮���ڰ��¼�����Ϊ���ź�״̬
	ResetEvent(hEvent);
	CloseHandle(hEvent);
	system("pause");
	return 0;
}