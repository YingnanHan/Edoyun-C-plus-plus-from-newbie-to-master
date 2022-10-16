#include <iostream>
#include<bitset>

int main()
{
	// λ���� ��λ�����
	int a{ (int)0b11111111011101111111111111111111 }; // 0xFFFFFFFF �����ŵ�����ֵ
	std::cout << std::bitset<32>(a) << std::endl; // ���ԭ����

	a <<= 8; // a = a << 8
	std::cout << std::bitset<32>(a) << std::endl; // �������8bit��Ľ��

	unsigned b{ (unsigned)a }; // ��ಹ��1
	b >>= 7; // �������7bit��Ľ��
	std::cout << std::bitset<32>(b) << std::endl;

	a >>= 7; // �������7bit��Ľ��
	std::cout << std::bitset<32>(a) << std::endl;

	int c{ -100 }; // ��������0 ��������1
	c >>= 2;
	std::cout << std::bitset<32>(c) << std::endl;

	std::cout << "===================================" << std::endl;
	// λ���� ȡ�������
	int test{ 0xffff };
	std::cout << std::bitset<32>(test) << std::endl;
	test = ~test;
	std::cout << std::bitset<32>(test) << std::endl;

	// λ���� �������
	int test1 = 0x2800; //ȡ��ǰ��λ
	std::cout << std::bitset<32>(test1) << std::endl;
	test1 = test1 & 0xFFFF >> 8;
	std::cout << std::bitset<32>(test1) << std::endl;

	return 0;
}