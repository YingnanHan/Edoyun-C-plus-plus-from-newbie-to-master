#include<iostream>

using namespace std;

int Add(int a, int b)
{
	return a + b;
}

/* 使用发布模式进行反汇编得到比较“干净”的汇编代码
* 01. 在属性里面设定关闭代码优化
* 02. 在main处下断点，观察反汇编如下
*		int Add(int a, int b)
		{
		00007FF640C31005  and         al,8    将al清零
			return a + b;
		00007FF640C31008  mov         eax,dword ptr [b]  
		00007FF640C3100C  mov         ecx,dword ptr [a]  
		00007FF640C31010  add         ecx,eax  
		00007FF640C31012  mov         eax,ecx  
		}

		int main()
		{
		00007FF640C31020  sub         rsp,28h
			Add(1, 2);
		00007FF640C31024  mov         edx,2
		00007FF640C31029  mov         ecx,1
		00007FF640C3102E  call        Add (07FF640C31000h) 括号里面的是函数的地址
			//std::cout << c;
		}
*/

int main()
{
	// 01
	Add(1, 2); //  函数的本质就是一块内存区域指令 Add表示这快内存的首地址
	//std::cout << c;
	//std::cout << Add << std::endl;

	// 02
	int c = Add(0x1234, 2);
	std::cout << Add;
	char* str = (char*)Add;
	for (int i = 0; i < 30; i++)// 打印出Add函数内容·以十六进制的方式
	{
		printf("%02X\n", (unsigned char)str[i]);
	}

}