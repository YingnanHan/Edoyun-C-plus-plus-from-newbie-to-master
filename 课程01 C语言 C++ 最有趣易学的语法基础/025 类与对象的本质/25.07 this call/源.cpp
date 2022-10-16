#include<iostream>

using namespace std;

class T
{
	int hp;
	int mp;
	inline static int count{ 0 };
public:
	int Add(int a, int b)
	{
		return this->hp + this->mp + a + b;
	}

	static int GetCount(int a, int b)
	{
		count++;
		return 2;
	}
};

int main()
{
	T t1;
//	t1.Add(100, 200);
	t1.GetCount(100, 200);
	return 0;
}

/*
#include<iostream>

using namespace std;

class T
{
	int hp;
	int mp;
	inline static int count{ 0 };
public:
	int Add(int a, int b)
	{
		return this->hp + this->mp + a + b;
	}

	static int GetCount(int a, int b)
	{
		00971002  in          al,dx
				count++;
		00971003  mov         eax,dword ptr [T::count (097338Ch)]
		00971008  add         eax,1
		0097100B  mov         dword ptr [T::count (097338Ch)],eax
				return 2;
		00971010  mov         eax,2
	}
	00971015  pop         ebp
	00971016  ret
--- ��Դ�ļ� -----------------------------------------------------------------------
00971017  int         3
00971018  int         3
00971019  int         3
0097101A  int         3
0097101B  int         3
0097101C  int         3
0097101D  int         3
0097101E  int         3
0097101F  int         3
--- C:\Users\20613\Desktop\Edoyun-C-plus-plus-from-newbie-to-master\�γ�01 C���� C++ ����Ȥ��ѧ���﷨����\025 �������ı���\25.07 this call\Դ.cpp
};

int main()
{
	00971020  push        ebp
	00971021  mov         ebp,esp
		T t1;
	//	t1.Add(100, 200);
		t1.GetCount(100, 200);
	00971023  push        0C8h
	00971028  push        64h
	0097102A  call        T::GetCount (0971000h)
	0097102F  add         esp,8
		return 0;
	00971032  xor         eax,eax
}
*/


/*
this call ���ù淶��
	_this call��C++�е����Ա��������ʱ����ĺ�������Լ��
	(1) �Ĵ���ecx����������ָ��
	(2) �������ҵ�����ջ
	(3) ��ջ�ɱ������߻ָ�

���еķǾ�̬��Ա������ʹ��thisָ�룬thisָ�뱾�����������ǰѶ����ָ��ͨ���Ĵ���ecx
�����Ա�����ģ�������еĳ�Ա���������������Ա��ʱ�򣬶���ͨ��ָ��+ƫ�Ƶ���ʽ����
�ʵģ������Ƿ���ȷʹ��ָ��this
*/

/*
��ľ�̬��Ա�����������ǲ���_cdeclԼ��
	�������ҵ�����ջ
	�ɵ����߻ָ���ջƽ��

	��Ϊ��ľ�̬��Ա���������Ͼ���һ����ͨ�ĺ��������Ը���û�д��ݶ���ָ�룬��ˣ�Ҳ�Ͳ��ܷ���
	���Ա����������ľ�̬��Ա�����������൱��һ��ȫ�ֱ��������Ź̶����ڴ��ַ����������޹�
	ϵ�����Ծ�̬��Ա��������û��ʵ���������ͨ�� ��::��̬��Ա ��������ʽ����
*/