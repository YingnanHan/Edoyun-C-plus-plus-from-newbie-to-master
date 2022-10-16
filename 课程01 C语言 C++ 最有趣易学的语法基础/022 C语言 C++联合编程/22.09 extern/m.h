#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

	int xve(); // 也可以在声明的时候声明函数是一个C风格的函数
	// int xve(int a, int b); //C风格不支持函数重载
#ifdef __cplusplus
}
#endif
