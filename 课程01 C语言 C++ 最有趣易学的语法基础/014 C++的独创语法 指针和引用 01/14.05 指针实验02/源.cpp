#include<iostream>

using namespace std;

int main()
{
	int a[]{ 1001,1002,1003,1004 };
	int* ptr{ &a[0] };

	int** pptr{ &ptr };//ȡ��ָ��ĵ�ַ
	int*** ppptr{ &pptr };//ȡ��ָ���ָ��ĵ�ַ

	*pptr = &a[1]; //ͨ��pptr�޸�ptr��ֵ

	cout << *ptr << endl;
	cout << **pptr << endl;
	cout << ***ppptr << endl;

	return 0;
}