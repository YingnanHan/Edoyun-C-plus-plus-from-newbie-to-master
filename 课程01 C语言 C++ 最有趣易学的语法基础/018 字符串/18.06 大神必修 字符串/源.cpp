// ���һ������,Ҫ���û�������Ӣ�Ļ�����ݣ���������ȷ�ĳ��Ȳ���ӡ����

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string strIn;
	std::cin >> strIn;

	int length{ 0 };
	for (int i = 0; strIn[i]; i++)
	{
		if (strIn[i] < 0)
		{
			i++;
		}
		length++;
	}
	cout << length;

	return 0;
}
