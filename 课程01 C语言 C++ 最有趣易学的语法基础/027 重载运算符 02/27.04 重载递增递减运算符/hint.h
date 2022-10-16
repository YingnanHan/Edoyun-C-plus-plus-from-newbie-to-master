#pragma once
class hint
{
	char* mem[4]; //定义一个地址数组，每一个元素是一个字节的地址(地址占位四个字节)
public:
	hint(int val = 0);
	hint(hint& val);
	~hint();
	operator int() const ;
	void operator=(int val);

	hint& operator++(); //前置++
	hint operator++(int x); //后置++
};

const hint& operator--(hint& val); /*前置--*/ //在类外部写解除了operator++ -- 参数必须是int类型的限制
const hint operator--(hint& val, int x); /*后置--*/ //在类外部写解除了operator++ -- 参数必须是int类型的限制

