#include<iostream>

using namespace std;

//int ave() // ��ΪC++�Ժ�����������������.cpp�ļ��еĺ�����ͬ����.c�ļ��еĺ��������ͻ
//{
//	return 1;
//}

extern "C"
{
	#include"e.h" // ��ʾͷ�ļ������ݾ���C����
}

extern "C" int xve() // ��cpp�ļ��б�ͨ��ʹ��C���Է��xve����
{
	return 3;
}

int main()
{
	// ave();// Ŀǰ������ǽ��ú�������C++����������������Է��ʲ���
	std::cout << ave() << std::endl;
	std::cout << pve() << std::endl;
	return 0;
}