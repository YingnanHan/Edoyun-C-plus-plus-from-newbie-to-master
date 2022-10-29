#include <stdio.h>
#include <windows.h>
#include <process.h>

char str[100];
HANDLE hEvent;

// 输入字母字符串 使用线程同步的方式来实现有几个字母A

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
	SetEvent(hEvent); // 把事件设置为有信号状态，上面那个函数才会执行
	return 0;
}

int main()
{
	HANDLE hThread1, hThread2;
	fputs("Input string:\n", stdout);
	fgets(str, 100, stdin);
	/*
		HANDLECreateEvent(
			LPSECURITY_ATTRIBUTESlpEventAttributes,	// 安全属性
			BOOLbManualReset,						// 复位方式 True必须用ResetEvent手动复原
			BOOLbInitialState,						// 初始状态 True初始状态为有信号状态， False为无信号状态
			LPCTSTRlpName							// 对象名称 NULL 无名的事件对象名称
		);

		lpEventAttributes[输入]
					一个指向SECURITY_ATTRIBUTES结构的指针，确定返回的句柄是否可被子进程继承。如果lpEventAttributes是NULL，此句柄不能被继承。
					Windows NT/2000：lpEventAttributes的结构中的成员为新的事件指定了一个安全符。如果lpEventAttributes是NULL，事件将获得一个默认的安全符。
		bManualReset[输入]
					指定将事件对象创建成手动复原还是自动复原。如果是TRUE，那么必须用ResetEvent函数来手工将事件的状态复原到无信号状态。如果设置为FALSE，当一个线程等待到事件信号后系统会自动将事件状态复原为无信号状态。
		bInitialState[输入]
					指定事件对象的初始状态。如果为TRUE，初始状态为有信号状态；否则为无信号状态。
		lpName[输入]
					指定事件的对象的名称，是一个以0结束的字符串指针。名称的字符格式限定在MAX_PATH之内。名字是对大小写敏感的。
					如果lpName指定的名字，与一个存在的命名的事件对象的名称相同，函数将请求EVENT_ALL_ACCESS来访问存在的对象。这时候，由于bManualReset和bInitialState参数已经在创建事件的进程中设置，这两个参数将被忽略。如果lpEventAttributes是参数不是NULL，它将确定此句柄是否可以被继承，但是其安全描述符成员将被忽略。
					如果lpName为NULL，将创建一个无名的事件对象。
					如果lpName的和一个存在的信号、互斥、等待计时器、作业或者是文件映射对象名称相同，函数将会失败，在GetLastError函数中将返回ERROR_INVALID_HANDLE。造成这种现象的原因是这些对象共享同一个命名空间。
	*/
	// 创建一个自动重置的事件，并且其初始值为无信号状态FALSE
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	hThread1 = (HANDLE)_beginthreadex(NULL, 0, NumberOfAs, NULL, 0, NULL);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, NumberOfOthers, NULL, 0, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	// 直到两个线程完全执行完毕之后，在把事件设置为无信号状态
	ResetEvent(hEvent);
	CloseHandle(hEvent);
	system("pause");
	return 0;
}