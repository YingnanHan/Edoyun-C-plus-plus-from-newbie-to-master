#include<iostream>

using namespace std;

int Add(int a, int b)
{
	return a + b;
}

/* ʹ�÷���ģʽ���з����õ��Ƚϡ��ɾ����Ļ�����
* 01. �����������趨�رմ����Ż�
* 02. ��main���¶ϵ㣬�۲췴�������
*		int Add(int a, int b)
		{
		00007FF640C31005  and         al,8    ��al����
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
		00007FF640C3102E  call        Add (07FF640C31000h) ����������Ǻ����ĵ�ַ
			//std::cout << c;
		}
*/

int main()
{
	// 01
	Add(1, 2); //  �����ı��ʾ���һ���ڴ�����ָ�� Add��ʾ����ڴ���׵�ַ
	//std::cout << c;
	//std::cout << Add << std::endl;

	// 02
	int c = Add(0x1234, 2);
	std::cout << Add;
	char* str = (char*)Add;
	for (int i = 0; i < 30; i++)// ��ӡ��Add�������ݡ���ʮ�����Ƶķ�ʽ
	{
		printf("%02X\n", (unsigned char)str[i]);
	}

}