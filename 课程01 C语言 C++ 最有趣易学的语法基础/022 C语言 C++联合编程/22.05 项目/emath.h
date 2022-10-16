// #pragma once //针对原文件来说，外部引用不论写多少遍，仅仅使用一次 可以使用防卫式声明来替代它

#ifndef __EMATH_H_
#define __EMATH_H_

#include"c.h"

int ave(int, int);
int bigger(int, int);
static int acount; // 初始定义或者声明的时候不需要加上extern，extern符号是相对于调用者所在的文件讲的

static int atest = 999;

// 静态函数
static void Test()
{

}

// 静态函数
// 内联函数
inline int TestA()
{
	return 1;
}

#endif // __EMATH_H_