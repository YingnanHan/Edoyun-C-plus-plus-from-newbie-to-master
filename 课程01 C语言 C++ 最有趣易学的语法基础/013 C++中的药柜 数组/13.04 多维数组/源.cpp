#include<iostream>

using namespace std;

int main()
{
	// ѧԺѧ����Ŀͳ�ƣ�����ӡѧ��
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
			cout << "��" << i << "���༶�ĵ�" << studentId[i][j] << "��ͬѧ" << "\t";
		}
		cout << endl;
	}

	return 0;
}