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

	for (int i = 0; i < 5; i++) // 数组越界会引发异常
	{
		ptrStudentId[i] = &studentId[i];
		cout << "内存地址:" << ptrStudentId[i] << "\t" << "值:" << studentId[i] << "\n";
	}
	*/

	int studentId[2][2]
	{
		{10001,10002},
		{10003,10004}
	};
	int* ptrStudentId[2][2];
	for (int i = 0; i < 2; i++) // 数组越界会引发异常
	{
		for (int j = 0; j < 2; j++)
		{
			ptrStudentId[i][j] = &studentId[i][j];
			cout << "内存地址:" << ptrStudentId[i][j] << "\t" << "值:" << studentId[i] << "\n";

		}
	}

	return 0;
}
