#pragma once
class hint
{
	char* mem[4]; //����һ����ַ���飬ÿһ��Ԫ����һ���ֽڵĵ�ַ(��ַռλ�ĸ��ֽ�)
public:
	hint(int val = 0);
	~hint();
	operator int();
	void operator=(int val);
};
