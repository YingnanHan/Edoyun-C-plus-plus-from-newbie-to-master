#pragma once
class hint
{
	char* mem[4]; //定义一个地址数组，每一个元素是一个字节的地址(地址占位四个字节)
public:
	hint(int val = 0);
	~hint();
	operator int();
	void operator=(int val);
};
