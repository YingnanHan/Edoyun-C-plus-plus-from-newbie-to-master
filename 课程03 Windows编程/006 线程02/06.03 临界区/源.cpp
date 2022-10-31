#include <stdio.h>
#include <windows.h>
#include <process.h>
int iTickets = 500;
CRITICAL_SECTION g_cs;
// A���� B����
DWORD WINAPI SellTicketA(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_cs);//�����ٽ���
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("A remain %d\n", iTickets);
			LeaveCriticalSection(&g_cs);//�뿪�ٽ���
		}
		else
		{
			LeaveCriticalSection(&g_cs);//�뿪�ٽ���
			break;
		}
	}
	return 0;
}
DWORD WINAPI SellTicketB(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_cs);//�����ٽ���
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
			LeaveCriticalSection(&g_cs);//�뿪�ٽ���
		}
		else
		{
			LeaveCriticalSection(&g_cs);//�뿪�ٽ���
			break;
		}
	}
	return 0;
}
int main()
{
	HANDLE hThreadA, hThreadB;
	hThreadA = CreateThread(NULL, 0, SellTicketA, NULL, 0, NULL); //2
	hThreadB = CreateThread(NULL, 0, SellTicketB, NULL, 0, NULL); //2
	CloseHandle(hThreadA); //1 ����Ҫʹ�����ü���Ϊ1
	CloseHandle(hThreadB); //1 ����Ҫʹ�����ü���Ϊ1
	InitializeCriticalSection(&g_cs); //��ʼ���ؼ������
	Sleep(40000);
	DeleteCriticalSection(&g_cs);//ɾ���ٽ���
	system("pause");
	return 0;
}