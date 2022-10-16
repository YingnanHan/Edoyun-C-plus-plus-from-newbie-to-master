// 设计一个程序,要求用户输入中英文混合内容，并计算正确的长度并打印出来

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
