#include<iostream>

/*
	������ͨ������������˵malloc��newû��ʲô���𣬵��Ƕ�������˵malloc�����Ƿ����ڴ�
	��new���˻�����ڴ�֮�⻹����ù��캯����delete�������ͷ��ڴ�ռ䣬���ҵ��õ�һ��
	Ԫ�ص�������������delete[]�������ͷ��ڴ�ռ䣬�������ÿһ��Ԫ�ص���������
*/

using namespace std;

class T
{
	int m_count{};
	inline static int count{};
public:
	T()
	{
		std::cout << "��" << ++count << "��T������" << std::endl;
		m_count = count;
	}
	~T()
	{
		std::cout << "��" << m_count-- << "��T������" << std::endl;
	}
	int test = 2;
};

int main()
{
	T* t1 = (T*)malloc(10 * sizeof(T));
	std::cout << t1[0].test;

	int* pint = (int*)malloc(10 * 4);
	pint[2] = 250;
	std::cout << pint[2] << std::endl;

	T* t2 = new T[100];

	// T* Tarr = new T[100];

	int* pint2 = new int[200];
	pint2[100] = 5000;
	// free(pint);
	delete pint; // ������ͨ�������ͣ������仰��һ����
	//free(t1); //�����ͷ�new�����Ŀռ䵫�ǲ��������������
	delete[] t2; // delete t2; �����´���
	
	std::cout << pint2[100] << std::endl;
	delete[] pint2;
	// std::cout << pint2[100] << std::endl; // �޷�����


	return 0;
}