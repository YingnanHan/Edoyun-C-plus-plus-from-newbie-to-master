#pragma once

// 头文件声明

extern int ave(int a, int b);
extern int bigger(int a, int b);
extern int account; //声明一个变量

// 静态函数仅仅在其定义的文件中有效 可以写在头文件中
static void test1()
{

}

// 内联函数同上
inline void test2()
{

}

// 同一个静态变量被导入不同的源文件中后，只在各自被导入的文件中独立，非静态变量与之相反