#include<iostream>

using namespace std;

const int SCREEN_WIDTH = 1980;
#define int float
#define true false // define��ȱ��
#define X //���X��������ôX�ᱻ�滻Ϊ���ַ�

// defineҲ������������ǣ���������һЩWindowsAPI���У���������ʾ
#define _int_
#define _out_
#define _TEST_ //���ඨ�岻��һ���������ʶ�����ӿո������

int ave(_int_ int a, _out_ int& b)
{
	return a / 2 + b / 2;
}

int main()
{
	int _TEST_ _a{ 250 };
#undef _TEST_ //ȡ��ʹ��_TEST_��,����Ͳ���������_TEST_��ʶ����ֵ��ע����ǣ�ɾ��˳���Ǳ���˳������Ǻ���ִ��˳��
	// int _TEST_ _b{ 250 }; // ����
	return 0;
}
