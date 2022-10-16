// 02.04 class2 printf测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	// 两种不同输出的比较
	printf("这是一个测试，关于printf\n 测试人员姓名\"HYN\"\n");
	std::cout << "这是一个测试，关于printf\n 测试人员姓名\"HYN\"";
	printf("\n");

	// 一些系统调用
	system("mode con cols=80 lines=40");	// 设置控制台窗口大小
	system("pause");						// 系统调用 Win+R 会有同样的效果
	system("cls");							// 系统调用 清除屏幕
	// system("shutdown /a");				// 关闭计算机
	system("color 13");						// 设置控制台背景为蓝色
	system("a.txt");						// 打开文件

	// 系统调用设置控制台颜色参考
	/*
		0 = 黑色	8 = 灰色
		1 = 蓝色	9 = 淡蓝色
		2 = 绿色	A = 淡绿色
		3 = 湖蓝色	B = 淡浅绿色
		4 = 红色	C = 淡红色
		5 = 紫色	D = 淡紫色
		6 = 黄色	E = 淡黄色
		7 = 白色	F = 亮白色
	*/

	return 0;
}