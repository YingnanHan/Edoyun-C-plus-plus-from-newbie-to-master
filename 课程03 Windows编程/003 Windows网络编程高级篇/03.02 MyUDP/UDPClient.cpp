#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<WinSock2.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("UDP Client\n");

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
	SOCKET sockCli = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sockCli)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}

	//	 2).����Ҫ���ӵķ�����
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // ʹ�ñ��ػػ���ַ
	addrSrv.sin_port = htons(6001); //���ö˿ں�
	addrSrv.sin_family = AF_INET; // ����IPv4Э����

	// 3.����UDP����
	int len = sizeof(SOCKADDR_IN);
	char sendBuf[100] = "hello";
	char recvBuf[100];
	sendto(sockCli, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrSrv, len);

	// 4.����UDP����
	recvfrom(sockCli, recvBuf, 100, 0, (SOCKADDR*)&addrSrv, &len);
	std::cout << recvBuf << std::endl; //��仰û�б�ִ��
	closesocket(sockCli);
	system("pause");
	return 0;
}