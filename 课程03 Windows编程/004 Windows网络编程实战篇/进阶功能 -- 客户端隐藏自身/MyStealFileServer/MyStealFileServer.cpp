#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_SIZE 1024

// ����̨������ֵ��ӡ����
void ErrorHandling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main()
{
	// 1.	��ʼ�������
	//   1).�����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsadata;
	int err;
	char msg[MAX_SIZE] = { 0 };

	wVersionRequested = MAKEWORD(2, 2);

	//	 2).��ʼ���׽��ֿ�
	err = WSAStartup(wVersionRequested, &wsadata);
	if (err != 0)
	{
		ErrorHandling("WSAStartup error");
	}
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
	{
		printf("LOBYTE errorNum = %d\n", GetLastError());
		WSACleanup();
		ErrorHandling("LOBYTE error");
		return -1;
	}

	// 2.	����SOCKET����
	SOCKET hServerSock = socket(PF_INET, SOCK_STREAM, 0); // AF_INET��PF_INET��һ���¶������������Ƶ�ʱ�������
	if (INVALID_SOCKET == hServerSock)
	{
		ErrorHandling("socket error");
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // ���ñ���IP��ַ ����������� ��Ϊ10060
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // ���ñ����˿ں� ����������� ��Ϊ10061

	//3.	����绰����
	//	1).	���׽��ֵ�����IP��ַ���˿ں�6000
	if (SOCKET_ERROR == bind(hServerSock, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		ErrorHandling("socket server");
	}

	//4.	���� listen
	if (SOCKET_ERROR == listen(hServerSock, 5))
	{
		ErrorHandling("listen error");
	}

	SOCKADDR_IN addrCli;
	int cliAdrSize = sizeof(SOCKADDR_IN);
	SOCKET cliSock;// ָ��ͻ��˵�socket����������������
	int strLen = 0;
	//5.	ѭ����������
	while (TRUE)
	{
		cliSock = accept(hServerSock, (SOCKADDR*)&addrCli, &cliAdrSize);
		if (cliSock == SOCKET_ERROR)
		{
			ErrorHandling("accept error");
		}
		memset(msg, 0, MAX_SIZE);
		while ((strLen = recv(cliSock, msg, MAX_SIZE, 0)) != 0 ) // ��client��������
		{
			puts(msg); // ����һ�����ݣ���ӡһ����־
		}
		closesocket(cliSock); // �رշֻ�
	}
	closesocket(hServerSock); //�ر�����
	WSACleanup();
	return 0;
}