#include<iostream>
#include<vector>

using namespace std;

int main()
{
	std::vector<int> studentId(5); // 设置默认初始值为0，一共有五元素，默认初始值为0

	studentId.assign(5, 100);

	int userId;
	do
	{
		std::cout << "请输入学号:";
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

	studentId.clear(); // 清空数组中内容
	if (studentId.empty())// 查看是否为空值
	{
		cout << "数组为空";
	}

	std::cout << studentId.size();

	for (int x : studentId)
	{
		std::cout << x << std::endl;
	}

	// 使用下标访问数组
	std::cout << "第0元素=" << studentId[0] << " " << std::endl;
	std::cout << "第0元素=" << studentId.at(0) << " " << std::endl;

	// 插入元素 

	return 0;
}