#pragma once
class hint
{
	char* mem[4]; //����һ����ַ���飬ÿһ��Ԫ����һ���ֽڵĵ�ַ(��ַռλ�ĸ��ֽ�)
public:
	hint(int val = 0);
	hint(hint& val);
	~hint();
	operator int() const ;
	void operator=(int val);

	hint& operator++(); //ǰ��++
	hint operator++(int x); //����++
};

const hint& operator--(hint& val); /*ǰ��--*/ //�����ⲿд�����operator++ -- ����������int���͵�����
const hint operator--(hint& val, int x); /*����--*/ //�����ⲿд�����operator++ -- ����������int���͵�����

