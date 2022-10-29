#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#pragma warning(disable:4996)
//
//// 客户端做的事情 
////			1.请求连接上线 
////			2.发消息 等待用户从控制台输入消息 发送到客户端
////			3.客户端等待服务端的消息
////			4.等待用户自己的关闭(下线 q)
//
//
//#include<stdio.h>
//#include<windows.h>
//#include<process.h>
//
//#pragma comment(lib, "ws2_32.lib")
//
//#define NAME_SIZE 256
//#define MAX_BUF_SIZE 1024
//
//char szName[NAME_SIZE] = "[DEFAULT]"; // 默认的昵称
//char szMsg[MAX_BUF_SIZE]; // 收发的数据
//
//unsigned WINAPI SendMsg(void* arg)
//{
//	SOCKET hClntSock = *((SOCKET*)arg);
//
//	char szNameMsg[NAME_SIZE + MAX_BUF_SIZE] = { 0 }; // 又要有昵称，又要有消息
//	while (1)
//	{
//		memset(szMsg, 0, MAX_BUF_SIZE);
//		// 阻塞在这一句，等待控制台的消息
//		fgets(szMsg, MAX_BUF_SIZE, stdin);
//		if (!strcmp(szMsg, "Q\n") || !strcmp(szMsg, "q\n"))
//		{
//			// 处理
//			closesocket(hClntSock);
//			exit(0);
//		}
//		// 拿到消息以后拼包发送给服务器
//		sprintf(szNameMsg, "%s %s", szName, szMsg);
//		send(hClntSock, szNameMsg, strlen(szNameMsg), 0);
//	}
//}
//
//unsigned WINAPI RecvMsg(void* arg)
//{
//	SOCKET hClntSock = *((SOCKET*)arg);
//
//	char szNameMsg[NAME_SIZE + MAX_BUF_SIZE] = { 0 }; // 又要有昵称，又要有消息
//	int iLen = 0;
//	while (1)
//	{
//		memset(szMsg, 0, NAME_SIZE + MAX_BUF_SIZE);
//		// 阻塞在这一句，等待来自于服务端的消息的消息
//		iLen = recv(hClntSock, szNameMsg, sizeof(szNameMsg), 0);
//		if (iLen == -1)
//		{
//			return 2;
//		}
//		szNameMsg[iLen] = 0;
//		fputs(szNameMsg, stdout); // 等到数据以后输出到控制台
//	}
//}
//
//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		printf("必须输入2个参数 包括昵称\n");
//		printf("启动方式 ：程序的当前目录 shift+鼠标右键 打开powershell");
//		printf("例如: MyThreadClient.exe WXM");
//		system("pause");
//		return -1;
//	}
//	sprintf(szName, "[%s]", argv[1]);
//	// 加载套接字库
//	WORD wVersionRequested;
//	WSADATA wsaData;
//	int err;
//	SOCKET hSock;
//	SOCKADDR_IN servAddr;
//	HANDLE hSendThread, hRecvThread;
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
//	// 1. 建立Socket
//	hSock = socket(PF_INET, SOCK_STREAM, 0);
//
//	// 2. 配置端口地址
//	memset(&servAddr, 0, sizeof(servAddr));
//	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//	servAddr.sin_family = AF_INET;
//	servAddr.sin_port = htons(9190);
//
//	// 3. 连接服务器
//	if (connect(hSock, (SOCKADDR*)&servAddr, sizeof(servAddr) == SOCKET_ERROR))
//	{
//		printf("connect error , error code = %d\n", GetLastError());
//			return -1;
//	}
//
//	// 4. 发送给服务端消息的线程
//	hSendThread = (HANDLE)_beginthreadex(NULL, 0, &SendMsg, (void*)&hSock, 0, NULL);
//
//
//	// 5. 起一个线程接收消息
//	hRecvThread = (HANDLE)_beginthreadex(NULL, 0, &RecvMsg, (void*)&hSock, 0, NULL);
//
//	// 等待hSendThread  hRecvThread 执行完
//	WaitForSingleObject(hRecvThread, INFINITE);
//	WaitForSingleObject(hSendThread, INFINITE);
//
//	// 关闭套接字
//	closesocket(hSock);
//	WSACleanup();
//
//	return 0;
//}


// 1 接收服务端的消息 安排一个工人 起一个线程接收消息
// 2 发送消息给服务端 安排一个工人 起一个线程发送消息
// 3 退出机制
#include <WinSock2.h>
#include <iostream>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#define NAME_SIZE 32
#define BUF_SIZE 256
char szName[NAME_SIZE] = "[DEFAULT]";
char szMsg[BUF_SIZE];
//发送消息给服务端
unsigned WINAPI SendMsg(void* arg)
{
	//1 接收传递过来的参数
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[NAME_SIZE + BUF_SIZE]; //又有名字，又有消息
	//循环接收来自于控制台的消息
	while (1)
	{
		fgets(szMsg, BUF_SIZE, stdin); //阻塞在这一句
		//退出机制 当收到q或Q 退出
		if (!strcmp(szMsg, "Q\n") || !strcmp(szMsg, "q\n"))
		{
			closesocket(hClntSock);
			exit(0);
		}
		sprintf(szNameMsg, "%s %s", szName, szMsg);//字符串拼接
		send(hClntSock, szNameMsg, strlen(szNameMsg), 0);//发送
	}
	return 0;
}
//接收服务端的消息
unsigned WINAPI RecvMsg(void* arg)
{
	//1 接收传递过来的参数
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[NAME_SIZE + BUF_SIZE]; //又有名字，又有消息
	int iLen = 0;
	while (1)
	{
		//recv阻塞
		iLen = recv(hClntSock, szNameMsg, NAME_SIZE + BUF_SIZE - 1, 0);
		//服务端断开
		if (iLen == -1)
		{
			return -1;
		}
		// szNameMsg的0到iLen -1 都是收到的数据 iLen个
		szNameMsg[iLen] = 0;
		//接收到的数据输出到控制台
		fputs(szNameMsg, stdout);
	}
	return 0;
}
// 带参数的main函数，用命令行启动 在当前目录按下shift + 鼠标右键 cmd
int main(int argc, char* argv[])
{
	// 加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	SOCKET hSock;
	SOCKADDR_IN servAdr;
	HANDLE hSendThread, hRecvThread;
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
	sprintf(szName, "[%s]", argv[1]);
	//1 建立socket
	hSock = socket(PF_INET, SOCK_STREAM, 0);
	// 2 配置端口和地址
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	servAdr.sin_family = AF_INET;
	servAdr.sin_port = htons(9190);
	// 3 连接服务器
	if (connect(hSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
	{
		printf("connect error error code = %d\n", GetLastError());
		return -1;
	}
	// 4 发送服务端的消息 安排一个工人 起一个线程发送消息
	hSendThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg,
		(void*)&hSock, 0, NULL);
	// 5 接收消息给服务端 安排一个工人 起一个线程接收消息
	hRecvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg,
		(void*)&hSock, 0, NULL);
	//等待内核对象的信号发生变化
	WaitForSingleObject(hSendThread, INFINITE);
	WaitForSingleObject(hRecvThread, INFINITE);
	// 6 关闭套接字
	closesocket(hSock);
	WSACleanup();
	return 0;
}