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
--- 无源文件 -----------------------------------------------------------------------
00971017  int         3
00971018  int         3
00971019  int         3
0097101A  int         3
0097101B  int         3
0097101C  int         3
0097101D  int         3
0097101E  int         3
0097101F  int         3
--- C:\Users\20613\Desktop\Edoyun-C-plus-plus-from-newbie-to-master\课程01 C语言 C++ 最有趣易学的语法基础\025 类与对象的本质\25.07 this call\源.cpp
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
this call 调用规范：
	_this call是C++中的类成员函数访问时定义的函数调用约定
	(1) 寄存器ecx用来存放类的指针
	(2) 参数由右到左入栈
	(3) 堆栈由被调用者恢复

类中的非静态成员都可以使用this指针，this指针本质上来讲就是把对象的指针通过寄存器ecx
传入成员函数的，因此类中的成员函数访问其变量成员的时候，都是通过指针+偏移的形式来访
问的，不管是否明确使用指针this
*/

/*
类的静态成员函数本质上是采用_cdecl约定
	参数从右到左入栈
	由调用者恢复堆栈平衡

	因为类的静态成员函数本质上就是一个普通的函数，所以根本没有传递对象指针，因此，也就不能访问
	其成员变量，而类的静态成员变量本质上相当于一个全局变量，有着固定的内存地址，与类对象并无关
	系，所以静态成员可以在类没有实例的情况下通过 类::静态成员 这样的形式访问
*/