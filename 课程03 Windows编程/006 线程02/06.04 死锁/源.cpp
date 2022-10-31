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
		EnterCriticalSection(&g_csA);//进入临界区
		printf("Begin A\n");
		Sleep(1);
		printf("End A\n");
		EnterCriticalSection(&g_csB);//进入临界区
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
			LeaveCriticalSection(&g_csB);//离开临界区
			LeaveCriticalSection(&g_csA);//离开临界区
		}
		else
		{
			LeaveCriticalSection(&g_csB);//离开临界区
			LeaveCriticalSection(&g_csA);//离开临界区
			break;
		}
	}
	return 0;
}

DWORD WINAPI SellTicketB(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_csB);//进入临界区
		printf("Begin B\n");
		Sleep(1);
		printf("End B\n");
		EnterCriticalSection(&g_csA);//进入临界区
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
			LeaveCriticalSection(&g_csA);//离开临界区
			LeaveCriticalSection(&g_csB);//离开临界区
		}
		else
		{
			LeaveCriticalSection(&g_csA);//离开临界区
			LeaveCriticalSection(&g_csB);//离开临界区
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
	CloseHandle(hThreadA); //1 这里要使得引用计数为1
	CloseHandle(hThreadB); //1 这里要使得引用计数为1

	InitializeCriticalSection(&g_csA); //初始化关键代码段A
	InitializeCriticalSection(&g_csB); //初始化关键代码段B
	Sleep(40000);
	DeleteCriticalSection(&g_csA);//删除临界区
	DeleteCriticalSection(&g_csB);//删除临界区
	system("pause");
	return 0;
}