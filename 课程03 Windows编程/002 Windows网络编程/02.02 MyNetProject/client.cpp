#define _WINSOCK_DEPRECATED_NO_WARNINGS
// Used as a Client
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("TCP Client\n");

	// 1.初始化网络库
	//   1).加载套接字库
	WORD wVersionRequested;
	WSADATA wsadata;
	int err;

	wVersionRequested = MAKEWORD(2, 2);

	//	 2).初始化套接字库
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

	// 2.安装电话机
	//   1).新建套接字
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockCli)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}

	//	 2).配置要连接的服务器
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("192.168.31.114"); // 配置本机IP地址 如果发生错误 则为10060
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // 配置本机端口号 如果发生错误 则为10061
	
	// 3.连接服务器
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("connect errorNum = %d\n", GetLastError());
		return -1;
	}
	
	// 4. 收发数据
	char recvBuf[100] = { 0 };
	int iLen = recv(sockCli, recvBuf, 100, 0);
	printf("recvBuf = %s\n", recvBuf);
	const char sendBuf[100] = "hahahahaha";
	iLen = send(sockCli, (char*)sendBuf, 100, 0);
	
	//5. 关闭套接字连接
	closesocket(sockCli);
	WSACleanup();
	system("pause");
	return 0;
}