#include<iostream>

using namespace std;

int ave(int a, int b)
{
	std::cout << __func__ << std::endl; // __func__ �귵�������ڵĺ�������
	return 0;
}

int main()
{
	std::cout << __func__ << std::endl; // __func__ �귵�������ڵĺ�������
	std::cout << __cplusplus << std::endl; // ���֪���ǲ���C���Ե�Դ�ļ�,�������һ�������ı�����ô������һ��C�����ļ�
	std::cout << __DATE__ << std::endl; // ��ȡԭ�ļ��ı���ʱ��
	std::cout << __TIME__ << std::endl; // ��ȡԭ�ļ���ת����Ԫת����ʱ��
	std::cout << __FILE__ << std::endl; // ��ȡת����Ԫ������
	ave(0, 1);;
	return 0;
}