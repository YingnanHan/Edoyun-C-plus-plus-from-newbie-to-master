///*
//服务器设计：多线程+网络编程+队列移位+线程同步 小项目
//			1.	对于每一个上线的客户端，服务端会起一个线程去维护
//			2.	将收到的消息转发给全部的客户端
//			3.	当某一个客户端下线的时候，需要处理断开的连接(如何处理)?
//*/
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include<WinSock2.h>
//#include<stdio.h>
//#include<windows.h>
//#include<process.h>
//
//#pragma comment(lib, "ws2_32.lib")
//
//#define MAX_CLNT 256
//#define MAX_BUF_SIZE 256
//
//SOCKET clnSocks[MAX_CLNT]; // 所有的连接的客户端的socket
//HANDLE hMutex; // 放在全局，因为每一个线程都需要使用
//int clntCnt = 0; // 客户端连接的个数
//
//// 将受到的消息转发给客户端
//void SendMsg(char* szMsg, int iLen)
//{
//	int i = 0;
//	WaitForSingleObject(hMutex, INFINITE);
//	for (i = 0; i < clntCnt; i++)
//	{
//		send(clnSocks[i], szMsg, iLen, 0); // 洪泛
//	}
//	ReleaseMutex(hMutex);
//}
//
//// 处理消息的工人 用于对某一个线程进行收发消息
//unsigned WINAPI  HandleCln(void* arg)
//{
//	// 此时连接的SOCKET的标记
//	SOCKET hClntSock = *((SOCKET*)arg);
//	int iLen = 0, i;
//	char szMsg[MAX_BUF_SIZE] = { 0 };
//	while (1)
//	{
//		iLen = recv(hClntSock, szMsg, sizeof(szMsg), 0);
//		if (iLen != -1)
//		{
//			// 将受到的消息转发给客户端
//			SendMsg(szMsg, iLen);
//		}
//		else
//		{
//			break;
//		}
//	}
//	printf("此时连接的数目为：%d\n", clntCnt);
//	WaitForSingleObject(hMutex, INFINITE);
//	//处理下线过程
//	// 1. 确定是哪一个链接下线了？遍历
//	for (i=0;i<clntCnt;i++)
//	{
//		if (hClntSock == clnSocks[i])
//		{
//			//已经找到了是哪一个连接下线了，移除这个链接
//			while (i++ < clntCnt)
//			{
//				clnSocks[i] = clnSocks[i + 1];
//			}
//			//移除完毕
//			break;
//		}
//	}
//	//移除之后总数减一
//	clntCnt--;
//	printf("断开此时的链接后，链接数目为：%d\n", clntCnt);
//	ReleaseMutex(hMutex);
//	closesocket(hClntSock); // 关闭对应的socket
//	return 0;
//}
//
//int main()
//{
//	printf("This is Server!\n");
//	// 加载套接字库
//	WORD wVersionRequested;
//	WSADATA wsaData;
//	int err;
//	HANDLE hThread;
//	wVersionRequested = MAKEWORD(1, 1);
//	// 初始化套接字库
//	err = WSAStartup(wVersionRequested, &wsaData);
//	if (err != 0)
//	{
//		return err;
//	}
//	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
//	{
//		WSACleanup();
//		return -1;
//	}
//	//创建一个锁 防止共有的变量被同时调用
//	hMutex = CreateMutex(NULL, FALSE, NULL);
//	// 创建服务器套接字
//	SOCKET hServerSock = socket(PF_INET, SOCK_STREAM, 0);
//
//	SOCKADDR_IN addrSrv;
//	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//	addrSrv.sin_family = AF_INET;
//	addrSrv.sin_port = htons(6000);
//
//	if (SOCKET_ERROR == bind(hServerSock, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
//	{
//		printf("bind error");
//		return -1;
//	}
//	// 开始监听
//	if (listen(hServerSock, 5) == SOCKET_ERROR)
//	{
//		printf("listen ERRORNUm = %d\n", GetLastError());
//		return -1;
//	}
//	printf("Start Listen!\n");
//	SOCKADDR_IN addrCli;
//	int len = sizeof(SOCKADDR_IN);
//	while (true)
//	{
//		//接受来自客户端的连接
//		
//		SOCKET sockConn = accept(hServerSock, (SOCKADDR*)&addrCli, &len);
//		//每来一个链接 就会起一个线程去维护
//		WaitForSingleObject(hMutex, INFINITE);
//		clnSocks[clntCnt++] = sockConn;
//		ReleaseMutex(hMutex);
//		hThread = (HANDLE)_beginthreadex(NULL, 0, HandleCln,(void*)&sockConn, 0, NULL);
//		printf("Connect client IP = %s \t，NUM = %d\n", inet_ntoa(addrCli.sin_addr), clntCnt); // 将实际的IP地址转化为字符串
//	}
//	closesocket(hServerSock);
//	WSACleanup();
//	return 0;
//}




//多线程+socket编程的一个联合使用
//用互斥体进行线程同步 socket编程 临界区 全局变量
#include <WinSock2.h>
#include <iostream>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#define MAX_CLNT 256
#define MAX_BUF_SIZE 256
SOCKET clntSocks[MAX_CLNT]; //所有的连接的客户端socket
HANDLE hMutex;
int clntCnt = 0; //当前连接的数目
// 服务端的设计：
// 1 每来一个连接，服务端起一个线程（安排一个工人）维护
// 2 将收到的消息转发给所有的客户端
// 3 某个连接断开，需要处理断开的连接
//发送给所有的客户端
void SendMsg(char* szMsg, int iLen)
{
	int i = 0;
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < clntCnt; i++)
	{
		send(clntSocks[i], szMsg, iLen, 0);
	}
	ReleaseMutex(hMutex);
}
//处理客户端连接的函数
unsigned WINAPI HandleCln(void* arg)
{
	//1 接收传递过来的参数
	SOCKET hClntSock = *((SOCKET*)arg);
	int iLen = 0, i;
	char szMsg[MAX_BUF_SIZE] = { 0 };
	//2 进行数据的收发 循环接收
	//接收到客户端的数据
	// while ((iLen = recv(hClntSock, szMsg, sizeof(szMsg),0)) != 0)
	// { //收到的数据立马发给所有的客户端
	// SendMsg(szMsg, iLen);
	// }
	while (1)
	{
		iLen = recv(hClntSock, szMsg, sizeof(szMsg), 0);
		if (iLen != -1)
		{
			//收到的数据立马发给所有的客户端
			SendMsg(szMsg, iLen);
		}
		else
		{
			break;
		}
	}
	printf("此时连接数目为 %d\n", clntCnt);
	//3 某个连接断开，需要处理断开的连接 遍历
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < clntCnt; i++)
	{
		if (hClntSock == clntSocks[i])
		{
			//移位
			while (i++ < clntCnt)
			{
				clntSocks[i] = clntSocks[i + 1];
			}
			break;
		}
	}
	clntCnt--; //当前连接数的一个自减
	printf("断开此时连接数目 %d", clntCnt);
	ReleaseMutex(hMutex);
	closesocket(hClntSock);
	return 0;
}
int main()
{
	// 加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	HANDLE hThread;
	wVersionRequested = MAKEWORD(1, 1);
	// 初始化套接字库
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return err;
	}
	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return -1;
	}
	//创建一个互斥对象
	hMutex = CreateMutex(NULL, FALSE, NULL);
	// 新建套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(9190);
	// 绑定套接字到本地IP地址，端口号9190
	if (bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		printf("bind ERRORnum = %d\n", GetLastError());
		return -1;
	}
	// 开始监听
	if (listen(sockSrv, 5) == SOCKET_ERROR)
	{
		printf("listen ERRORnum = %d\n", GetLastError());
		return -1;
	}
	printf("start listen\n");
	SOCKADDR_IN addrCli;
	int len = sizeof(SOCKADDR);
	while (1)
	{
		// 接收客户连接 sockConn此时来的客户端连接
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrCli, &len);
		//每来一个连接，服务端起一个线程（安排一个工人）维护客户端的连接
		//每来一个连接，全局数组应该加一个成员，最大连接数加1
		WaitForSingleObject(hMutex, INFINITE);
		clntSocks[clntCnt++] = sockConn;
		ReleaseMutex(hMutex);
		hThread = (HANDLE)_beginthreadex(NULL, 0, HandleCln,
			(void*)&sockConn, 0, NULL);
		printf("Connect client IP: %s \n", inet_ntoa(addrCli.sin_addr));
		printf("Connect client num: %d \n", clntCnt);
	}
	closesocket(sockSrv);
	WSACleanup();
	return 0;
}