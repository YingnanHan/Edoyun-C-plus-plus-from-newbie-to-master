#define _WINSOCK_DEPRECATED_NO_WARNINGS
// Used as a Client
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("TCP Client\n");

	// 1.��ʼ�������
	//   1).�����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsadata;
	int err;

	wVersionRequested = MAKEWORD(2, 2);

	//	 2).��ʼ���׽��ֿ�
	err = WSAStartup(wVersionRequested, &wsadata);
	if (err != 0)
	{
		printf("WSAStartup errorNum = %d\n", GetLastError());
		return err;
	}
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
	{
		printf("LOBYTE errorNum = %d\n", GetLastError());
		WSACleanup();
		return -1;
	}

	// 2.��װ�绰��
	//   1).�½��׽���
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockCli)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}

	//	 2).����Ҫ���ӵķ�����
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("192.168.31.114"); // ���ñ���IP��ַ ����������� ��Ϊ10060
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // ���ñ����˿ں� ����������� ��Ϊ10061
	
	// 3.���ӷ�����
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("connect errorNum = %d\n", GetLastError());
		return -1;
	}
	
	// 4. �շ�����
	char recvBuf[100] = { 0 };
	int iLen = recv(sockCli, recvBuf, 100, 0);
	printf("recvBuf = %s\n", recvBuf);
	const char sendBuf[100] = "hahahahaha";
	iLen = send(sockCli, (char*)sendBuf, 100, 0);
	
	//5. �ر��׽�������
	closesocket(sockCli);
	WSACleanup();
	system("pause");
	return 0;
}