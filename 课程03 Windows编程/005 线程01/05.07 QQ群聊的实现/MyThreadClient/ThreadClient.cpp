#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#pragma warning(disable:4996)
//
//// �ͻ����������� 
////			1.������������ 
////			2.����Ϣ �ȴ��û��ӿ���̨������Ϣ ���͵��ͻ���
////			3.�ͻ��˵ȴ�����˵���Ϣ
////			4.�ȴ��û��Լ��Ĺر�(���� q)
//
//
//#include<stdio.h>
//#include<windows.h>
//#include<process.h>
//
//#pragma comment(lib, "ws2_32.lib")
//
//#define NAME_SIZE 256
//#define MAX_BUF_SIZE 1024
//
//char szName[NAME_SIZE] = "[DEFAULT]"; // Ĭ�ϵ��ǳ�
//char szMsg[MAX_BUF_SIZE]; // �շ�������
//
//unsigned WINAPI SendMsg(void* arg)
//{
//	SOCKET hClntSock = *((SOCKET*)arg);
//
//	char szNameMsg[NAME_SIZE + MAX_BUF_SIZE] = { 0 }; // ��Ҫ���ǳƣ���Ҫ����Ϣ
//	while (1)
//	{
//		memset(szMsg, 0, MAX_BUF_SIZE);
//		// ��������һ�䣬�ȴ�����̨����Ϣ
//		fgets(szMsg, MAX_BUF_SIZE, stdin);
//		if (!strcmp(szMsg, "Q\n") || !strcmp(szMsg, "q\n"))
//		{
//			// ����
//			closesocket(hClntSock);
//			exit(0);
//		}
//		// �õ���Ϣ�Ժ�ƴ�����͸�������
//		sprintf(szNameMsg, "%s %s", szName, szMsg);
//		send(hClntSock, szNameMsg, strlen(szNameMsg), 0);
//	}
//}
//
//unsigned WINAPI RecvMsg(void* arg)
//{
//	SOCKET hClntSock = *((SOCKET*)arg);
//
//	char szNameMsg[NAME_SIZE + MAX_BUF_SIZE] = { 0 }; // ��Ҫ���ǳƣ���Ҫ����Ϣ
//	int iLen = 0;
//	while (1)
//	{
//		memset(szMsg, 0, NAME_SIZE + MAX_BUF_SIZE);
//		// ��������һ�䣬�ȴ������ڷ���˵���Ϣ����Ϣ
//		iLen = recv(hClntSock, szNameMsg, sizeof(szNameMsg), 0);
//		if (iLen == -1)
//		{
//			return 2;
//		}
//		szNameMsg[iLen] = 0;
//		fputs(szNameMsg, stdout); // �ȵ������Ժ����������̨
//	}
//}
//
//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		printf("��������2������ �����ǳ�\n");
//		printf("������ʽ ������ĵ�ǰĿ¼ shift+����Ҽ� ��powershell");
//		printf("����: MyThreadClient.exe WXM");
//		system("pause");
//		return -1;
//	}
//	sprintf(szName, "[%s]", argv[1]);
//	// �����׽��ֿ�
//	WORD wVersionRequested;
//	WSADATA wsaData;
//	int err;
//	SOCKET hSock;
//	SOCKADDR_IN servAddr;
//	HANDLE hSendThread, hRecvThread;
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
//	// 1. ����Socket
//	hSock = socket(PF_INET, SOCK_STREAM, 0);
//
//	// 2. ���ö˿ڵ�ַ
//	memset(&servAddr, 0, sizeof(servAddr));
//	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//	servAddr.sin_family = AF_INET;
//	servAddr.sin_port = htons(9190);
//
//	// 3. ���ӷ�����
//	if (connect(hSock, (SOCKADDR*)&servAddr, sizeof(servAddr) == SOCKET_ERROR))
//	{
//		printf("connect error , error code = %d\n", GetLastError());
//			return -1;
//	}
//
//	// 4. ���͸��������Ϣ���߳�
//	hSendThread = (HANDLE)_beginthreadex(NULL, 0, &SendMsg, (void*)&hSock, 0, NULL);
//
//
//	// 5. ��һ���߳̽�����Ϣ
//	hRecvThread = (HANDLE)_beginthreadex(NULL, 0, &RecvMsg, (void*)&hSock, 0, NULL);
//
//	// �ȴ�hSendThread  hRecvThread ִ����
//	WaitForSingleObject(hRecvThread, INFINITE);
//	WaitForSingleObject(hSendThread, INFINITE);
//
//	// �ر��׽���
//	closesocket(hSock);
//	WSACleanup();
//
//	return 0;
//}


// 1 ���շ���˵���Ϣ ����һ������ ��һ���߳̽�����Ϣ
// 2 ������Ϣ������� ����һ������ ��һ���̷߳�����Ϣ
// 3 �˳�����
#include <WinSock2.h>
#include <iostream>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#define NAME_SIZE 32
#define BUF_SIZE 256
char szName[NAME_SIZE] = "[DEFAULT]";
char szMsg[BUF_SIZE];
//������Ϣ�������
unsigned WINAPI SendMsg(void* arg)
{
	//1 ���մ��ݹ����Ĳ���
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[NAME_SIZE + BUF_SIZE]; //�������֣�������Ϣ
	//ѭ�����������ڿ���̨����Ϣ
	while (1)
	{
		fgets(szMsg, BUF_SIZE, stdin); //��������һ��
		//�˳����� ���յ�q��Q �˳�
		if (!strcmp(szMsg, "Q\n") || !strcmp(szMsg, "q\n"))
		{
			closesocket(hClntSock);
			exit(0);
		}
		sprintf(szNameMsg, "%s %s", szName, szMsg);//�ַ���ƴ��
		send(hClntSock, szNameMsg, strlen(szNameMsg), 0);//����
	}
	return 0;
}
//���շ���˵���Ϣ
unsigned WINAPI RecvMsg(void* arg)
{
	//1 ���մ��ݹ����Ĳ���
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[NAME_SIZE + BUF_SIZE]; //�������֣�������Ϣ
	int iLen = 0;
	while (1)
	{
		//recv����
		iLen = recv(hClntSock, szNameMsg, NAME_SIZE + BUF_SIZE - 1, 0);
		//����˶Ͽ�
		if (iLen == -1)
		{
			return -1;
		}
		// szNameMsg��0��iLen -1 �����յ������� iLen��
		szNameMsg[iLen] = 0;
		//���յ����������������̨
		fputs(szNameMsg, stdout);
	}
	return 0;
}
// ��������main������������������ �ڵ�ǰĿ¼����shift + ����Ҽ� cmd
int main(int argc, char* argv[])
{
	// �����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	SOCKET hSock;
	SOCKADDR_IN servAdr;
	HANDLE hSendThread, hRecvThread;
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
	sprintf(szName, "[%s]", argv[1]);
	//1 ����socket
	hSock = socket(PF_INET, SOCK_STREAM, 0);
	// 2 ���ö˿ں͵�ַ
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	servAdr.sin_family = AF_INET;
	servAdr.sin_port = htons(9190);
	// 3 ���ӷ�����
	if (connect(hSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
	{
		printf("connect error error code = %d\n", GetLastError());
		return -1;
	}
	// 4 ���ͷ���˵���Ϣ ����һ������ ��һ���̷߳�����Ϣ
	hSendThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg,
		(void*)&hSock, 0, NULL);
	// 5 ������Ϣ������� ����һ������ ��һ���߳̽�����Ϣ
	hRecvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg,
		(void*)&hSock, 0, NULL);
	//�ȴ��ں˶�����źŷ����仯
	WaitForSingleObject(hSendThread, INFINITE);
	WaitForSingleObject(hRecvThread, INFINITE);
	// 6 �ر��׽���
	closesocket(hSock);
	WSACleanup();
	return 0;
}