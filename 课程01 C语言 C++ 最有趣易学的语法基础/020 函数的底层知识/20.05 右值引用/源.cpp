#include<iostream>

void Add(int&& a)
{
	std::cout << a;
}

struct Role
{
	int hp;
	int mp;
};

Role CreateMonster()
{
	Role rt{ 100, 200 };
	return rt;
}

void Show(Role &&r1) // 临时用一下临时变量r1，然后再删除,这样不会是确实浪费空间
{
	std::cout << r1.hp << " " << r1.mp << std::endl;
}

int main()
{
	/*案例01*/

	//int c = 232 + 11; // 左值 c存储在栈空间中
	//int& d = c; // 左值引用
	//int&& e = 320; // 右值引用 右值引用无法写入值
	////Add(100 + 111); //参数是右值 这个值会临时存储在寄存器里面 所以他不能是左值引用 一般情况下一些编译器会对此进行优化
	//int a[10];
	//// *(a + 1) = 100; //左值
	//e = 1500;
	//int x = c + 320 + 250;
	//Add(static_cast<int&&>(x));
	//Add(c + 320 + 250); // 右值引用的优点之一是可以节省一个临时变量

	/*案例02*/
	Show(CreateMonster());
}