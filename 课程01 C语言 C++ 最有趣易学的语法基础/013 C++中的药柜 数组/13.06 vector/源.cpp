#include<iostream>
#include<vector>

using namespace std;

int main()
{
	std::vector<int> studentId(5); // ����Ĭ�ϳ�ʼֵΪ0��һ������Ԫ�أ�Ĭ�ϳ�ʼֵΪ0

	studentId.assign(5, 100);

	int userId;
	do
	{
		std::cout << "������ѧ��:";
		std::cin >> userId;
		if (!userId)
		{
			break;
		}
		else
		{
			studentId.push_back(userId);
		}
	} while (true);

	studentId.clear(); // �������������
	if (studentId.empty())// �鿴�Ƿ�Ϊ��ֵ
	{
		cout << "����Ϊ��";
	}

	std::cout << studentId.size();

	for (int x : studentId)
	{
		std::cout << x << std::endl;
	}

	// ʹ���±��������
	std::cout << "��0Ԫ��=" << studentId[0] << " " << std::endl;
	std::cout << "��0Ԫ��=" << studentId.at(0) << " " << std::endl;

	// ����Ԫ�� 

	return 0;
}