#include<iostream>

extern "C"
{
	#include"e.h" // ��ͷ�ļ��е�����������C���Ե�ģʽ����
}


using namespace std;

// ��������Ա���ͨ������ΪC++�ٱ��뺯����ʱ���ǵ������أ�һ�������ڱ����ʱ��
// �������ֱ��޸Ĺ��ˣ�����.c�ļ��е�ave��.cpp�е�aveʵ�������ڴ��в�����ͬ

// ��C++����������ΪC�����
extern "C" void hello()
{
	std::cout << "Hello" << endl;
}

int main()
{
	return 0;
}