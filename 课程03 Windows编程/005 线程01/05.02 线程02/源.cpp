#include<stdio.h>
#include<windows.h>
#include<process.h>

unsigned WINAPI thread_main_hong(void* arg)
{
	int cnt = *((int*)arg); // �������޸�Ϊint����
	for (int i = 0; i < cnt; i++)
	{
		printf("push-up\n");
		Sleep(3000);
	}
	return 0;
}

unsigned WINAPI thread_main_ming(void* arg)
{
	int cnt = *((int*)arg); // �������޸�Ϊint����
	for (int i = 0; i < cnt; i++)
	{
		printf("shake head\n");
		Sleep(4000);
	}
	return 0;
}

unsigned WINAPI thread_main_wang(void* arg) // WINAPI == __stdcall
{
	int cnt = *((int*)arg); // �������޸�Ϊint����
	for (int i = 0; i < cnt; i++)
	{
		printf("singing\n");
		Sleep(3000);
	}
	return 0;
}

int main()
{
	int hong = 20;
	int ming = 30;
	int wang = 50;
	/*
	unsigned long _beginthreadex
	(
		void * _Security,									//��1����������ȫ���ԣ�NULLΪĬ�ϰ�ȫ����
		unsigned  _StackSize,								//��2��������ָ���̶߳�ջ�Ĵ�С�����Ϊ0�����̶߳�ջ��С�ʹ��������̵߳���ͬ��һ����0
		unsigned ( __stdcall * _StartAddress )( void * ),	//��3��������ָ���̺߳����ĵ�ַ��Ҳ�����̵߳���ִ�еĺ�����ַ(�ú������Ƽ��ɣ��������ƾͱ�ʾ��ַ)
		void * _Arglist,									//��4�����������ݸ��̵߳Ĳ�����ָ�룬����ͨ����������ָ�룬���̺߳�������ת��Ϊ��Ӧ���ָ��
		unsigned int  _Initflag,							//��5���������̳߳�ʼ״̬��0:�������У�CREATE_SUSPEND��suspended�����ң�
		unsigned int*  _Thrdaddr							//��6�����������ڼ�¼�߳�ID�ĵ�ַ
	);
	*/

	unsigned int hong_id, ming_id, wang_id;
	// ͬʱ���������̣߳�û����������һ���ľ��Դ���֮˵��ʲôʱ��ִ����һ���߳̽�����CPU�����й�
	_beginthreadex(NULL, 0, &thread_main_hong, (void*)&hong, 0, &hong_id);
	_beginthreadex(NULL, 0, &thread_main_ming, (void*)&ming, 0, &ming_id);
	_beginthreadex(NULL, 0, &thread_main_wang, (void*)&wang, 0, &wang_id);

	Sleep(100000); // ����100s
	system("pause");
	return 0;
}