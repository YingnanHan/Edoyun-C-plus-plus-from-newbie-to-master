#include<iostream>

using namespace std;

int main()
{
	unsigned x;
	std::cout << "��������Ҫ������ڴ�Ĵ�С:";
	std::cin >> x;
	int* pc{};
	int* pm{};
	int* bm{}; // ���ڱ���

	pm = (int*)malloc(sizeof(int) * x);// ����void*���� Ȼ��ǿ��ת�� ��ʼ���ڴ���Ԫ�����
	pc = (int*)calloc(x, sizeof(int)); // ����void*���� Ȼ��ǿ��ת�� ��ʼ���ڴ���Ԫ��Ϊ��

	std::cout << pm[0] << std::endl;
	std::cout << pc[0] << std::endl;

	if (pc == nullptr)
	{
		std::cout << "�ڴ����ʧ��" << std::endl;
	}
	else
	{
		pm[0] = 952;
		pm[1] = 953;
		pm[2] = pm[0] * pm[1];
		std::cout << pm[0] << " " << pm[1] << " " << pm[2] << std::endl;
	}

	std::cout << "������������Ҫ�ֱ�����ڴ��С:";
	std::cin >> x;
	bm = pm;
	pm = (int*)realloc(pm, x);
	std::cout << pm << "=========" << bm << std::endl; // reallocǰ���ַ�ı仯���
	// ������ڴ�ҳ���й�

	return 0;
}