#include<iostream>
#include"edoyun.h"

#define VERSION "1.0"

int ave(int a, int b)
{
	return a * b / 2;
}

namespace edoyun
{
	const char* GetVersion()
	{
		const char* str = VERSION;
		return str;
	}
}

// ① 设置 常规 -> 配置类型 -> 静态库
// ② 写完代码之后在解决方案处右键点击生成
// ③ 在工程目录的Debug文件夹下找到 22.11 创建自己的sdkedoyun.lib
// ④ 新建文件夹edoyun, 22.11 创建自己的sdkedoyun.lib 将其移动进去
// ⑤ 将edoyun.h移动到对应的文件夹中，这个文件就是SDK的对应的"说明书"