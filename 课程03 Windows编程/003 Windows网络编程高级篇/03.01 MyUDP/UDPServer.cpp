#include<WinSock2.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("UDP Server\n");

	// 1.��ʼ�������
	//   1).�����׽��ֿ�
	WORD wVersion;
	WSADATA wsaData;
	int err;

	wVersion = MAKEWORD(2, 2);

	//	 2).��ʼ���׽��ֿ�
	err = WSAStartup(wVersion, &wsaData);
	if (err != 0)
	{
		printf("WSAStartup errorNum = %d\n", GetLastError());
		return err;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("LOBYTE errorNum = %d\n", GetLastError());
		WSACleanup();
		return -1;
	}

	// 2.��װ�绰��
	//	 1).�����׽��� TCP -> SOCK_STREAM,  UDP -> DGRAM
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sockSrv)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}

	//	 2).����Ҫ���ӵķ�����(�����ַ�Ͷ˿�)
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // host to net in long ��IP��ַת��Ϊ������
	addrSrv.sin_family = AF_INET; // ����IPv4Э����
	addrSrv.sin_port = htons(6001); //���ö˿ں� // host to net in short ���˿ں�ת��Ϊ������

	// 3.���ӷ�����
	if (SOCKET_ERROR == bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("bind errorNum = %d\n", GetLastError());
		return -1;
	}

	// 4. �շ�����
	SOCKADDR_IN addrCli; // Ŀ���׽��ֵĵ�ַ��
	int len = sizeof(SOCKADDR_IN);

	char recvBuf[100] = { 0 };
	char sendBuf[100] = { 0 };

	while (1)
	{
		recvfrom(sockSrv, recvBuf, 100,0, (SOCKADDR*)&addrCli, &len); 
		std::cout << recvBuf << std::endl;

		sprintf_s(sendBuf, 100, "Ack: %s", recvBuf);
		sendto(sockSrv, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrCli, len);
	}
	// 5. �ر��׽���
	closesocket(sockSrv);
	system("pause");
	return 0;
}