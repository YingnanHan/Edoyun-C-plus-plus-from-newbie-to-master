#include<iostream>

using namespace std;

int ave(int a, int b)
{
	std::cout << __func__ << std::endl;
	std::cout << __FUNCTION__ << std::endl; //���غ�������
	std::cout << __FUNCDNAME__ << std::endl;//���غ������������� ר��Ӧ��C++���������
	std::cout << __FUNCSIG__ << std::endl;//��ȡ�����ĵ��÷�ʽ ���η�ʽ
	return 0;
}

int main()
{
#ifdef _CHAR_UNSIGNED // ���char����Ϊ�޷�����ú�Ϊ1
	std::cout << "_CHAR_UNSIGNED";
#endif

	// __COUNTER__���ڼ���������һ������ֵ��һ

#ifdef _DEBUG
	// ���ڵ���ģʽ
#endif
	ave(1,1);
	return 0;
}