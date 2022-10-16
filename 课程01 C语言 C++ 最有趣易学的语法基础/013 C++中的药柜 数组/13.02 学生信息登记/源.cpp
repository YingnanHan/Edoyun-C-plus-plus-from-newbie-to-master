#include<iostream>

using namespace std;

int main()
{
	int studentId[100]{};
	// 100
	int indexId{ 0 };
	while (indexId < 100)
	{
		cout << "输入学号(输入0查看已登记的学生信息):";
		cin >> studentId[indexId];
		if (studentId[indexId] == 0)
		{
			system("cls");
			for (int i = 0; i < indexId; i++)
			{
				std::cout << i << "号 学生学号" << studentId[i] << std::endl;
			}
		}
		else
		{
			indexId++;
		}
		std::cout << sizeof studentId / sizeof(int) << " ";
	}

	return 0;
}