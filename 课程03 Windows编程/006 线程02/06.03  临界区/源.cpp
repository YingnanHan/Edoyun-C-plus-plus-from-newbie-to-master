#include <stdio.h>
#include <windows.h>
#include <process.h>
int iTickets = 500;
CRITICAL_SECTION g_cs;
// A窗口 B窗口
DWORD WINAPI SellTicketA(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_cs);//进入临界区
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("A remain %d\n", iTickets);
			LeaveCriticalSection(&g_cs);//离开临界区
		}
		else
		{
			LeaveCriticalSection(&g_cs);//离开临界区
			break;
		}
	}
	return 0;
}
DWORD WINAPI SellTicketB(void* lpParam)
{
	while (1)
	{
		EnterCriticalSection(&g_cs);//进入临界区
		if (iTickets > 0)
		{
			Sleep(1);
			iTickets--;
			printf("B remain %d\n", iTickets);
			LeaveCriticalSection(&g_cs);//离开临界区
		}
		else
		{
			LeaveCriticalSection(&g_cs);//离开临界区
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
	InitializeCriticalSection(&g_cs); //初始化关键代码段
	Sleep(40000);
	DeleteCriticalSection(&g_cs);//删除临界区
	system("pause");
	return 0;
}