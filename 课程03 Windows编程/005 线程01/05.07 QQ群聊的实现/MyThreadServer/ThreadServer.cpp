///*
//��������ƣ����߳�+������+������λ+�߳�ͬ�� С��Ŀ
//			1.	����ÿһ�����ߵĿͻ��ˣ�����˻���һ���߳�ȥά��
//			2.	���յ�����Ϣת����ȫ���Ŀͻ���
//			3.	��ĳһ���ͻ������ߵ�ʱ����Ҫ����Ͽ�������(��δ���)?
//*/
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include<WinSock2.h>
//#include<stdio.h>
//#include<windows.h>
//#include<process.h>
//
//#pragma comment(lib, "ws2_32.lib")
//
//#define MAX_CLNT 256
//#define MAX_BUF_SIZE 256
//
//SOCKET clnSocks[MAX_CLNT]; // ���е����ӵĿͻ��˵�socket
//HANDLE hMutex; // ����ȫ�֣���Ϊÿһ���̶߳���Ҫʹ��
//int clntCnt = 0; // �ͻ������ӵĸ���
//
//// ���ܵ�����Ϣת�����ͻ���
//void SendMsg(char* szMsg, int iLen)
//{
//	int i = 0;
//	WaitForSingleObject(hMutex, INFINITE);
//	for (i = 0; i < clntCnt; i++)
//	{
//		send(clnSocks[i], szMsg, iLen, 0); // �鷺
//	}
//	ReleaseMutex(hMutex);
//}
//
//// ������Ϣ�Ĺ��� ���ڶ�ĳһ���߳̽����շ���Ϣ
//unsigned WINAPI  HandleCln(void* arg)
//{
//	// ��ʱ���ӵ�SOCKET�ı��
//	SOCKET hClntSock = *((SOCKET*)arg);
//	int iLen = 0, i;
//	char szMsg[MAX_BUF_SIZE] = { 0 };
//	while (1)
//	{
//		iLen = recv(hClntSock, szMsg, sizeof(szMsg), 0);
//		if (iLen != -1)
//		{
//			// ���ܵ�����Ϣת�����ͻ���
//			SendMsg(szMsg, iLen);
//		}
//		else
//		{
//			break;
//		}
//	}
//	printf("��ʱ���ӵ���ĿΪ��%d\n", clntCnt);
//	WaitForSingleObject(hMutex, INFINITE);
//	//�������߹���
//	// 1. ȷ������һ�����������ˣ�����
//	for (i=0;i<clntCnt;i++)
//	{
//		if (hClntSock == clnSocks[i])
//		{
//			//�Ѿ��ҵ�������һ�����������ˣ��Ƴ��������
//			while (i++ < clntCnt)
//			{
//				clnSocks[i] = clnSocks[i + 1];
//			}
//			//�Ƴ����
//			break;
//		}
//	}
//	//�Ƴ�֮��������һ
//	clntCnt--;
//	printf("�Ͽ���ʱ�����Ӻ�������ĿΪ��%d\n", clntCnt);
//	ReleaseMutex(hMutex);
//	closesocket(hClntSock); // �رն�Ӧ��socket
//	return 0;
//}
//
//int main()
//{
//	printf("This is Server!\n");
//	// �����׽��ֿ�
//	WORD wVersionRequested;
//	WSADATA wsaData;
//	int err;
//	HANDLE hThread;
//	wVersionRequested = MAKEWORD(1, 1);
//	// ��ʼ���׽��ֿ�
//	err = WSAStartup(wVersionRequested, &wsaData);
//	if (err != 0)
//	{
//		return err;
//	}
//	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
//	{
//		WSACleanup();
//		return -1;
//	}
//	//����һ���� ��ֹ���еı�����ͬʱ����
//	hMutex = CreateMutex(NULL, FALSE, NULL);
//	// �����������׽���
//	SOCKET hServerSock = socket(PF_INET, SOCK_STREAM, 0);
//
//	SOCKADDR_IN addrSrv;
//	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//	addrSrv.sin_family = AF_INET;
//	addrSrv.sin_port = htons(6000);
//
//	if (SOCKET_ERROR == bind(hServerSock, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
//	{
//		printf("bind error");
//		return -1;
//	}
//	// ��ʼ����
//	if (listen(hServerSock, 5) == SOCKET_ERROR)
//	{
//		printf("listen ERRORNUm = %d\n", GetLastError());
//		return -1;
//	}
//	printf("Start Listen!\n");
//	SOCKADDR_IN addrCli;
//	int len = sizeof(SOCKADDR_IN);
//	while (true)
//	{
//		//�������Կͻ��˵�����
//		
//		SOCKET sockConn = accept(hServerSock, (SOCKADDR*)&addrCli, &len);
//		//ÿ��һ������ �ͻ���һ���߳�ȥά��
//		WaitForSingleObject(hMutex, INFINITE);
//		clnSocks[clntCnt++] = sockConn;
//		ReleaseMutex(hMutex);
//		hThread = (HANDLE)_beginthreadex(NULL, 0, HandleCln,(void*)&sockConn, 0, NULL);
//		printf("Connect client IP = %s \t��NUM = %d\n", inet_ntoa(addrCli.sin_addr), clntCnt); // ��ʵ�ʵ�IP��ַת��Ϊ�ַ���
//	}
//	closesocket(hServerSock);
//	WSACleanup();
//	return 0;
//}




//���߳�+socket��̵�һ������ʹ��
//�û���������߳�ͬ�� socket��� �ٽ��� ȫ�ֱ���
#include <WinSock2.h>
#include <iostream>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#define MAX_CLNT 256
#define MAX_BUF_SIZE 256
SOCKET clntSocks[MAX_CLNT]; //���е����ӵĿͻ���socket
HANDLE hMutex;
int clntCnt = 0; //��ǰ���ӵ���Ŀ
// ����˵���ƣ�
// 1 ÿ��һ�����ӣ��������һ���̣߳�����һ�����ˣ�ά��
// 2 ���յ�����Ϣת�������еĿͻ���
// 3 ĳ�����ӶϿ�����Ҫ����Ͽ�������
//���͸����еĿͻ���
void SendMsg(char* szMsg, int iLen)
{
	int i = 0;
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < clntCnt; i++)
	{
		send(clntSocks[i], szMsg, iLen, 0);
	}
	ReleaseMutex(hMutex);
}
//����ͻ������ӵĺ���
unsigned WINAPI HandleCln(void* arg)
{
	//1 ���մ��ݹ����Ĳ���
	SOCKET hClntSock = *((SOCKET*)arg);
	int iLen = 0, i;
	char szMsg[MAX_BUF_SIZE] = { 0 };
	//2 �������ݵ��շ� ѭ������
	//���յ��ͻ��˵�����
	// while ((iLen = recv(hClntSock, szMsg, sizeof(szMsg),0)) != 0)
	// { //�յ����������������еĿͻ���
	// SendMsg(szMsg, iLen);
	// }
	while (1)
	{
		iLen = recv(hClntSock, szMsg, sizeof(szMsg), 0);
		if (iLen != -1)
		{
			//�յ����������������еĿͻ���
			SendMsg(szMsg, iLen);
		}
		else
		{
			break;
		}
	}
	printf("��ʱ������ĿΪ %d\n", clntCnt);
	//3 ĳ�����ӶϿ�����Ҫ����Ͽ������� ����
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < clntCnt; i++)
	{
		if (hClntSock == clntSocks[i])
		{
			//��λ
			while (i++ < clntCnt)
			{
				clntSocks[i] = clntSocks[i + 1];
			}
			break;
		}
	}
	clntCnt--; //��ǰ��������һ���Լ�
	printf("�Ͽ���ʱ������Ŀ %d", clntCnt);
	ReleaseMutex(hMutex);
	closesocket(hClntSock);
	return 0;
}
int main()
{
	// �����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	HANDLE hThread;
	wVersionRequested = MAKEWORD(1, 1);
	// ��ʼ���׽��ֿ�
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return err;
	}
	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return -1;
	}
	//����һ���������
	hMutex = CreateMutex(NULL, FALSE, NULL);
	// �½��׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(9190);
	// ���׽��ֵ�����IP��ַ���˿ں�9190
	if (bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		printf("bind ERRORnum = %d\n", GetLastError());
		return -1;
	}
	// ��ʼ����
	if (listen(sockSrv, 5) == SOCKET_ERROR)
	{
		printf("listen ERRORnum = %d\n", GetLastError());
		return -1;
	}
	printf("start listen\n");
	SOCKADDR_IN addrCli;
	int len = sizeof(SOCKADDR);
	while (1)
	{
		// ���տͻ����� sockConn��ʱ���Ŀͻ�������
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrCli, &len);
		//ÿ��һ�����ӣ��������һ���̣߳�����һ�����ˣ�ά���ͻ��˵�����
		//ÿ��һ�����ӣ�ȫ������Ӧ�ü�һ����Ա�������������1
		WaitForSingleObject(hMutex, INFINITE);
		clntSocks[clntCnt++] = sockConn;
		ReleaseMutex(hMutex);
		hThread = (HANDLE)_beginthreadex(NULL, 0, HandleCln,
			(void*)&sockConn, 0, NULL);
		printf("Connect client IP: %s \n", inet_ntoa(addrCli.sin_addr));
		printf("Connect client num: %d \n", clntCnt);
	}
	closesocket(sockSrv);
	WSACleanup();
	return 0;
}