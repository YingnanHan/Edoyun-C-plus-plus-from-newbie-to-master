#include<WinSock2.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("UDP Server\n");

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
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sockSrv)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}

	//	 2).配置要连接的服务器(分配地址和端口)
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // host to net in long 将IP地址转化为长整型
	addrSrv.sin_family = AF_INET; // 设置IPv4协议族
	addrSrv.sin_port = htons(6001); //设置端口号 // host to net in short 将端口号转化为短整形

	// 3.连接服务器
	if (SOCKET_ERROR == bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("bind errorNum = %d\n", GetLastError());
		return -1;
	}

	// 4. 收发数据
	SOCKADDR_IN addrCli; // 目的套接字的地址族
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
	// 5. 关闭套接字
	closesocket(sockSrv);
	system("pause");
	return 0;
}