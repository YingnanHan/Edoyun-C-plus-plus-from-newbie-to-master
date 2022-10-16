#define _WINSOCK_DEPRECATED_NO_WARNINGS
// Used as a Server
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	printf("Server\n");
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
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockSrv)
	{
		printf("socket errorNum = %d\n", GetLastError());
		return -1;
	}
	//   2).给服务器配置电话号码即IP地址，端口号6000
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	// 3. 绑定套接字到本地IP地址，端口号为6000
	if (SOCKET_ERROR == bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("bind errorNum = %d\n", GetLastError());
		return -1;
	}
	// 4. 监听消息
	if (SOCKET_ERROR == listen(sockSrv, 5)) // 如果队列已经满了，那么启用更多的客户端将导致10061端口号方面的错误，因为不能容下更多的客户端
	{
		printf("listen errorNum = %d\n", GetLastError());
		return -1;
	}
	// 5. 数据发送接收准备
	SOCKADDR_IN addrCli;
	int len = sizeof(SOCKADDR);
	while (TRUE)
	{
		// 6.分配一台"分电话机"去执行"任务"
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrCli, &len);
		char sendBuf[100] = { 0 };
		sprintf_s(sendBuf, 100, "Welcome %s to bingo!", inet_ntoa(addrCli.sin_addr));
		//   1) 发送数据
		int iLen = send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		if (iLen < 0)
		{
			printf("send errorNum = %d\n", GetLastError());
			return -1;
		}
		char recvBuf[100] = { 0 };
		//   2) 接受数据
		iLen = recv(sockConn, recvBuf, 100, 0);
		if (iLen < 0)
		{
			printf("recv errorNum = %d\n", GetLastError());
			return -1;
		}
		//   3) 打印接收到的数据
		printf("recvBuf = %s:\n", recvBuf);
		//   4) 关闭分机
		closesocket(sockConn);
	}
	// 7.关闭总机
	closesocket(sockSrv);
	WSACleanup();
	system("pause");
	return 0;
}