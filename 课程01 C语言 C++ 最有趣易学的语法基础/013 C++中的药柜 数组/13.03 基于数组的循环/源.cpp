#include<iostream>

using namespace std;

int main()
{
	int studentId[]{
		10001,
		10002,
		10003,
		10004,
		10005,
	};
	for (int i = 0; i < sizeof(studentId) / sizeof(int); i++)
	{
		cout << "#" << i << "\t" << studentId[i] << std::endl;
	}
	std::cout << "################" << std::endl;
	int i = 0;
	for (auto No : studentId)
	{
		cout << "#" << i << "\t" << No << std::endl;
		i += 1;
	}
	std::cout << "################" << std::endl;
	i = 0;
	for (int No : studentId)
	{
		cout << "#" << i << "\t" << No << std::endl;
		i += 1;
	}
	return 0;
}