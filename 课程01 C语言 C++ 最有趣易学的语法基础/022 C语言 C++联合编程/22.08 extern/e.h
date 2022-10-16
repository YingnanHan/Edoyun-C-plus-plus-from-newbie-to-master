#pragma once

//extern "C" int ave(); // 这句话是专门给C++编译器看的，让调用该函数的.cpp文件明白
//					  // 需要以C风格来对函数进行编译
//
//extern "C" int pve(); // 这句话是专门给C++编译器看的，让调用该函数的.cpp文件明白
//					  // 需要以C风格来对函数进行编译

// 上面的几句话也可以统一写成
extern "C"
{
	int ave();
	int pve();
}