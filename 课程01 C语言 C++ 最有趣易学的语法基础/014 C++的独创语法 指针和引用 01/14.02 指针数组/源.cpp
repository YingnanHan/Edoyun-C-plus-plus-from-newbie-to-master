#include<iostream>

using namespace std;

int main()
{
	/*
	int studentId[5]
	{
		10001,10002,10003,10004,10005
	};
	int* ptrStudentId[5];

	for (int i = 0; i < 5; i++) // ����Խ��������쳣
	{
		ptrStudentId[i] = &studentId[i];
		cout << "�ڴ��ַ:" << ptrStudentId[i] << "\t" << "ֵ:" << studentId[i] << "\n";
	}
	*/

	int studentId[2][2]
	{
		{10001,10002},
		{10003,10004}
	};
	int* ptrStudentId[2][2];
	for (int i = 0; i < 2; i++) // ����Խ��������쳣
	{
		for (int j = 0; j < 2; j++)
		{
			ptrStudentId[i][j] = &studentId[i][j];
			cout << "�ڴ��ַ:" << ptrStudentId[i][j] << "\t" << "ֵ:" << studentId[i] << "\n";

		}
	}

	return 0;
}
