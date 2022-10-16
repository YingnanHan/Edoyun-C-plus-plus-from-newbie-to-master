#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout << std::fixed; // �������Ϊ6λС����С��������
	cout << 3.14 << endl;

	cout << std::scientific; // ���ÿ�ѧ������
	cout << 3.14 << endl;

	cout << std::defaultfloat; // �������ΪĬ��
	cout << 3.14 << endl;

	cout << std::setprecision(3); // �������3Ϊ��Ч����
	cout << 3.1415925 << endl;

	cout << 314 << endl; // ���ʮ��������

	cout << std::hex; // �������ʮ������
	cout << 314 << endl;

	cout << std::oct; // ��������˽���
	cout << 314 << endl;

	cout << std::showbase;
	cout << std::hex; // ���������ǰ��ʮ������
	cout << 314 << endl;

	cout << std::showbase << std::oct; // ���������ǰ���˽���
	cout << 314 << endl;

	cout << std::dec;
	std::cout << std::setw(10) << 3.14 << std::endl; // ���ù̶�λ��
	std::cout << std::setfill('&') << std::setw(20) << 3.14 << std::endl; //���ù̶���ȿ�����������

	// ���Ҷ���
	cout << std::defaultfloat;
	std::cout << std::left; // ���������
	cout << std::dec;
	std::cout << std::setw(10) << 3.14 << std::endl; // ���ù̶�λ��
	std::cout << std::setfill('&') << std::setw(20) << 3.14 << std::endl; //���ù̶���ȿ�����������
	// ת���Ʊ��\t
	std::cout << "\t���!!\b\a" << endl;

	return 0;
}
