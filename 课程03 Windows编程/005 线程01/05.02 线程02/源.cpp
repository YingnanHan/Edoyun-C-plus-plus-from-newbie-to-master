#include<stdio.h>
#include<windows.h>
#include<process.h>

unsigned WINAPI thread_main_hong(void* arg)
{
	int cnt = *((int*)arg); // 将参数修改为int类型
	for (int i = 0; i < cnt; i++)
	{
		printf("push-up\n");
		Sleep(3000);
	}
	return 0;
}

unsigned WINAPI thread_main_ming(void* arg)
{
	int cnt = *((int*)arg); // 将参数修改为int类型
	for (int i = 0; i < cnt; i++)
	{
		printf("shake head\n");
		Sleep(4000);
	}
	return 0;
}

unsigned WINAPI thread_main_wang(void* arg) // WINAPI == __stdcall
{
	int cnt = *((int*)arg); // 将参数修改为int类型
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
		void * _Security,									//第1个参数：安全属性，NULL为默认安全属性
		unsigned  _StackSize,								//第2个参数：指定线程堆栈的大小。如果为0，则线程堆栈大小和创建它的线程的相同。一般用0
		unsigned ( __stdcall * _StartAddress )( void * ),	//第3个参数：指定线程函数的地址，也就是线程调用执行的函数地址(用函数名称即可，函数名称就表示地址)
		void * _Arglist,									//第4个参数：传递给线程的参数的指针，可以通过传入对象的指针，在线程函数中再转化为对应类的指针
		unsigned int  _Initflag,							//第5个参数：线程初始状态，0:立即运行；CREATE_SUSPEND：suspended（悬挂）
		unsigned int*  _Thrdaddr							//第6个参数：用于记录线程ID的地址
	);
	*/

	unsigned int hong_id, ming_id, wang_id;
	// 同时启动三个线程，没有限制性哪一个的绝对次序之说，什么时刻执行哪一个线程仅仅与CPU调度有关
	_beginthreadex(NULL, 0, &thread_main_hong, (void*)&hong, 0, &hong_id);
	_beginthreadex(NULL, 0, &thread_main_ming, (void*)&ming, 0, &ming_id);
	_beginthreadex(NULL, 0, &thread_main_wang, (void*)&wang, 0, &wang_id);

	Sleep(100000); // 休眠100s
	system("pause");
	return 0;
}