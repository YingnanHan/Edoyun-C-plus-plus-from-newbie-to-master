#define _WINSOCK_DEPRECATED_NO_WARNINGS
// Used as a Server
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("Server\n");
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
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockSrv)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}
	//   2).�����������õ绰���뼴IP��ַ���˿ں�6000
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	// 3. ���׽��ֵ�����IP��ַ���˿ں�Ϊ6000
	if (SOCKET_ERROR == bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("bind errorNum = %d\n", GetLastError());
		return -1;
	}
	// 4. ������Ϣ
	if (SOCKET_ERROR == listen(sockSrv, 5)) // ��������Ѿ����ˣ���ô���ø���Ŀͻ��˽�����10061�˿ںŷ���Ĵ�����Ϊ�������¸���Ŀͻ���
	{
		printf("listen errorNum = %d\n", GetLastError());
		return -1;
	}
	// 5. ���ݷ��ͽ���׼��
	SOCKADDR_IN addrCli;
	int len = sizeof(SOCKADDR);
	while (TRUE)
	{
		// 6.����һ̨"�ֵ绰��"ȥִ��"����"
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrCli, &len);
		char sendBuf[100] = { 0 };
		sprintf_s(sendBuf, 100, "Welcome %s to bingo!", inet_ntoa(addrCli.sin_addr));
		//   1) ��������
		int iLen = send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		if (iLen < 0)
		{
			printf("send errorNum = %d\n", GetLastError());
			return -1;
		}
		char recvBuf[100] = { 0 };
		//   2) ��������
		iLen = recv(sockConn, recvBuf, 100, 0);
		if (iLen < 0)
		{
			printf("recv errorNum = %d\n", GetLastError());
			return -1;
		}
		//   3) ��ӡ���յ�������
		printf("recvBuf = %s:\n", recvBuf);
		//   4) �رշֻ�
		closesocket(sockConn);
	}
	// 7.�ر��ܻ�
	closesocket(sockSrv);
	WSACleanup();
	system("pause");
	return 0;
}