#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_SIZE 1024

// 控制台错误码值打印函数
void ErrorHandling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main()
{
	// 1.	初始化网络库
	//   1).加载套接字库
	WORD wVersionRequested;
	WSADATA wsadata;
	int err;
	char msg[MAX_SIZE] = { 0 };

	wVersionRequested = MAKEWORD(2, 2);

	//	 2).初始化套接字库
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

	// 2.	创建SOCKET链接
	SOCKET hServerSock = socket(PF_INET, SOCK_STREAM, 0); // AF_INET与PF_INET是一回事儿，设计者在设计的时候多虑了
	if (INVALID_SOCKET == hServerSock)
	{
		ErrorHandling("socket error");
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // 配置本机IP地址 如果发生错误 则为10060
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // 配置本机端口号 如果发生错误 则为10061

	//3.	分配电话号码
	//	1).	绑定套接字到本地IP地址，端口号6000
	if (SOCKET_ERROR == bind(hServerSock, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		ErrorHandling("socket server");
	}

	//4.	监听 listen
	if (SOCKET_ERROR == listen(hServerSock, 5))
	{
		ErrorHandling("listen error");
	}

	SOCKADDR_IN addrCli;
	int cliAdrSize = sizeof(SOCKADDR_IN);
	SOCKET cliSock;// 指向客户端的socket，在这里无需配置
	int strLen = 0;
	//5.	循环接受数据
	while (TRUE)
	{
		cliSock = accept(hServerSock, (SOCKADDR*)&addrCli, &cliAdrSize);
		if (cliSock == SOCKET_ERROR)
		{
			ErrorHandling("accept error");
		}
		memset(msg, 0, MAX_SIZE);
		while ((strLen = recv(cliSock, msg, MAX_SIZE, 0)) != 0 ) // 从client接受数据
		{
			puts(msg); // 接受一次数据，打印一次日志
		}
		closesocket(cliSock); // 关闭分机
	}
	closesocket(hServerSock); //关闭主机
	WSACleanup();
	return 0;
}