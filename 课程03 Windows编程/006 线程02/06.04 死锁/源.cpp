#include <stdio.h>
#include <windows.h>
#include <process.h>

int iTickets = 5000;
CRITICAL_SECTION g_csA;
CRITICAL_SECTION g_csB;

DWORD WINAPI SellTicketA(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_csA);//�����ٽ���
		printf("Begin A\n");
		Sleep(1);
		printf("End A\n");
		EnterCriticalSection(&g_csB);//�����ٽ���
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
			LeaveCriticalSection(&g_csB);//�뿪�ٽ���
			LeaveCriticalSection(&g_csA);//�뿪�ٽ���
		}
		else
		{
			LeaveCriticalSection(&g_csB);//�뿪�ٽ���
			LeaveCriticalSection(&g_csA);//�뿪�ٽ���
			break;
		}
	}
	return 0;
}

DWORD WINAPI SellTicketB(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_csB);//�����ٽ���
		printf("Begin B\n");
		Sleep(1);
		printf("End B\n");
		EnterCriticalSection(&g_csA);//�����ٽ���
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
			LeaveCriticalSection(&g_csA);//�뿪�ٽ���
			LeaveCriticalSection(&g_csB);//�뿪�ٽ���
		}
		else
		{
			LeaveCriticalSection(&g_csA);//�뿪�ٽ���
			LeaveCriticalSection(&g_csB);//�뿪�ٽ���
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

	InitializeCriticalSection(&g_csA); //��ʼ���ؼ������A
	InitializeCriticalSection(&g_csB); //��ʼ���ؼ������B
	Sleep(40000);
	DeleteCriticalSection(&g_csA);//ɾ���ٽ���
	DeleteCriticalSection(&g_csB);//ɾ���ٽ���
	system("pause");
	return 0;
}