#include<iostream>

using namespace std;

int main()
{
	int studentId[100]{};
	// 100
	int indexId{ 0 };
	while (indexId < 100)
	{
		cout << "����ѧ��(����0�鿴�ѵǼǵ�ѧ����Ϣ):";
		cin >> studentId[indexId];
		if (studentId[indexId] == 0)
		{
			system("cls");
			for (int i = 0; i < indexId; i++)
			{
				std::cout << i << "�� ѧ��ѧ��" << studentId[i] << std::endl;
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