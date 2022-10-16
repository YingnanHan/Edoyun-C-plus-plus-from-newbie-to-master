#include<iostream>

using namespace std;

int main()
{
	// 学院学生数目统计，并打印学号
	int studentId[3][5] =
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	};

	for (int i = 0; i < sizeof studentId / sizeof(studentId[0]); i++)
	{
		for (int j = 0; j < sizeof studentId[0] / sizeof(int); j++)
		{
			cout << "第" << i << "个班级的第" << studentId[i][j] << "号同学" << "\t";
		}
		cout << endl;
	}

	return 0;
}