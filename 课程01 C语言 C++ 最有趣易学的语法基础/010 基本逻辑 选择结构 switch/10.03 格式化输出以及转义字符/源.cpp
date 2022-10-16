#include<iostream>
#include<conio.h>

using namespace std;

#pragma warning(disable : 4996)

int main()
{
	//// 传统C输入方式
	//printf("I'm very handsome!\n"); // 基本用法
	//printf("I'm %s\,and I'm %d years old.\n","Mike",19); // 基本格式化用法
	//printf("I'm of %f cm's height\n", 190); // 格式化用法
	//printf("My lucky number is 0x%x\n", 999); //十六进制格式化
	//printf("My lucky number is %+05d\n", 999); //十进制位宽度=5格式化

	//int age{ 0 };
	//int a;
	//int b;
	//int c;
	//int d;
	//scanf("%d%d%d%d", &a, &b, &c, &d);//C形式输入
	//printf("%d%d%d%d", &a, &b, &c, &d);//C形式输出

	// 现代方式
	int uin = _getch(); // 从控制台输入内容一个字符 返回ASCII码值
	std::cout << uin << std::endl;


	return 0;
}