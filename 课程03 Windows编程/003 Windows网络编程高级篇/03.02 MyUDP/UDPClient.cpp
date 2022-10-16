#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<WinSock2.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("UDP Client\n");

	// 1.初始化网络库
	//   1).加载套接字库
	WORD wVersion;
	WSADATA wsaData;
	int err;

	wVersion = MAKEWORD(2, 2);

	//	 2).初始化套接字库
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

	// 2.安装电话机
	//	 1).创建套接字 TCP -> SOCK_STREAM,  UDP -> DGRAM
	SOCKET sockCli = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sockCli)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}

	//	 2).配置要连接的服务器
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // 使用本地回环地址
	addrSrv.sin_port = htons(6001); //设置端口号
	addrSrv.sin_family = AF_INET; // 设置IPv4协议族

	// 3.发送UDP数据
	int len = sizeof(SOCKADDR_IN);
	char sendBuf[100] = "hello";
	char recvBuf[100];
	sendto(sockCli, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrSrv, len);

	// 4.接受UDP数据
	recvfrom(sockCli, recvBuf, 100, 0, (SOCKADDR*)&addrSrv, &len);
	std::cout << recvBuf << std::endl; //这句话没有被执行
	closesocket(sockCli);
	system("pause");
	return 0;
}