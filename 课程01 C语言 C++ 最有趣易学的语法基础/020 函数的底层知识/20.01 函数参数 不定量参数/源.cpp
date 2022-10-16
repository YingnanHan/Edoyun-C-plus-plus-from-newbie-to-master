// �ɱ�������� ���ƽ����

#include<iostream>
#include<cstdarg>

using namespace std;

struct SArg
{
	int count;//�����ĸ���
	char* cMem; //��������һ���ڴ��ַ
};

int Average(int count, ...) // �����Ǳ�����һ�������ĵ�ַ�ռ��
{
	va_list arg; // va_list == char* ��ζ�ȡ����ȡ���ڵ�ַ���ڴ�����
	va_start(arg, count); // ��arg�������ݵ����ݰ���count��ָ���Ĵ�С�����ɱ����������arg
	// va_arg(arg, int); // ��ȡ�ɱ�����б��е�����
	int sum{};
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg); //�ͷ�arg��Դ
	sum /= count;
	return sum;
}

int Ave(SArg& y)
{
	int sum{};
	int* ary = (int*)y.cMem;
	for (int i = 0; i < y.count; i++)
	{
		sum += ary[i];
	}
	return sum /= y.count;
}

void main()
{
	// ��
	int x = Average(5, 6, 67, 2, 78, 87, 32.3,2);
	std::cout << "ƽ����:" << x;

	// ��
	SArg y;
	y.count = 5;
	y.cMem = (char*)new int[5] {562,(int)321.23f,256,541,120}; // ���ݸ�������һ��ָ��

	// ��
	x = Ave(y);
	std::cout << "ƽ����:" << x;
}