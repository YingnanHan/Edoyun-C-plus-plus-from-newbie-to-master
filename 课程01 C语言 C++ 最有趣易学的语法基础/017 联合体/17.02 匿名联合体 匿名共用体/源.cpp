#include<iostream>

using namespace std;

union
{
	short	sHP;
	int		nHP;
	double	fHP;
} ls; //���������� ���ǲ������ظ�ʹ��

struct
{
	int size;
} ss; //�����ṹ�� ��������������ͬ ������ʱ��������

// �������������ݽṹ�л�ʹ�õ�Union���ҽ�������һ����ô�ͻ�ʹ�õ�����������

int main()
{
	ss.size = 10;
	cout << ss.size << endl;
	return 0;
}