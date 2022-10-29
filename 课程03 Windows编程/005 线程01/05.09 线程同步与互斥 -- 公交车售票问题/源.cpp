#include <stdio.h>
#include <windows.h>
#include <process.h>
int iTickets = 100;
HANDLE g_hEvent;
DWORD WINAPI SellTicketA(void* lpParam)
{
	while (1)
	{
		WaitForSingleObject(g_hEvent, INFINITE);
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("A remain %d\n", iTickets);
		}
		else
		{
			break;
		}
		SetEvent(g_hEvent); // 设置为有信号状态
	}
	return 0;
}
DWORD WINAPI SellTicketB(void* lpParam)
{
	while (1)
	{
		WaitForSingleObject(g_hEvent, INFINITE);
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
		}
		else
		{
			break;
		}
		SetEvent(g_hEvent);
	}
	return 0;//0 内核对象被销毁
}
int main()
{
	HANDLE hThreadA, hThreadB;
	hThreadA = CreateThread(NULL, 0, SellTicketA, NULL, 0, 0);// 2
	hThreadB = CreateThread(NULL, 0, SellTicketB, NULL, 0, 0);
	CloseHandle(hThreadA); //1
	CloseHandle(hThreadB);
	// 手动重置 无信号状态(未触发状态)
	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetEvent(g_hEvent);
	Sleep(4000);
	CloseHandle(g_hEvent);
	system("pause");
	return 0;
}