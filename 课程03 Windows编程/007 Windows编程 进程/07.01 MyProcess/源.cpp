// 拉起谷歌浏览器 并且打开百度

#include<stdio.h>
#include<windows.h>

int RunExe()
{
	STARTUPINFO strStartupInfo;
	memset(&strStartupInfo, 0, sizeof(strStartupInfo));
	strStartupInfo.cb = sizeof(strStartupInfo);
	PROCESS_INFORMATION szProcessInformation;
	memset(&szProcessInformation, 0, sizeof(szProcessInformation));

	TCHAR szCommandLine[] = L"\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" http;//www.baidu.com/s?w=美国";

	int bRet = CreateProcess(NULL, szCommandLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &strStartupInfo, &szProcessInformation);
	if (bRet)
	{
		// 创建成功
		printf("Create Success bRet = %d\n", bRet);
		WaitForSingleObject(szProcessInformation.hProcess, 3000);
		printf("Create Success szProcess Information hProcess = %d\n", szProcessInformation.hProcess);
		printf("Create Success szProcess Information hThread = %d\n", szProcessInformation.hThread);
		printf("Create Success szProcess Information dwProcessId = %d\n", szProcessInformation.dwProcessId);
		printf("Create Success szProcess Information dwThreadId = %d\n", szProcessInformation.dwThreadId);
		CloseHandle(szProcessInformation.hProcess);
		CloseHandle(szProcessInformation.hThread);
		szProcessInformation.hProcess = NULL;
		szProcessInformation.hThread = NULL;
		szProcessInformation.dwProcessId = 0;
		szProcessInformation.dwThreadId = 0;
	}
	else
	{
		printf("Create Failed bRet = %d\n", bRet);
		printf("Error Code = %d\n", GetLastError());
	}
	return 0;
}

int main()
{
	printf("This is Chrome!!");
	RunExe();
	system("pause");
	return 0;
}